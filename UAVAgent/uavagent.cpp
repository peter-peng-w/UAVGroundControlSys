#include "uavagent.h"
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QHostAddress>
#include <QUdpSocket>
#include <qmath.h>
#include <QtMath>
#include <QTime>

UAVAgent::UAVAgent(QWidget *parent)
    : QWidget(parent)
{
    // init
    uav_data.uav_lat = 0.000;
    uav_data.uav_lng = 0.000;
    uav_data.uav_status = 0;
    update_time_period = 1000;
    myPort = 3355;
    isStarted = false;
    directionAngle = 0;

    qDebug() << "agent build success... data size:";
    qDebug() << sizeof(uav_data);
    qDebug() << "\n";

    setWindowTitle(tr("UAV Agent"));
    startBtn = new QPushButton(tr("Start"), this);
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(startBtn);
    connect(startBtn, SIGNAL(clicked(bool)), this, SLOT(StartBtnClicked()));

    udpSocket = new QUdpSocket(this);

    isSuccessBind = udpSocket->bind(myPort);
    if(!isSuccessBind)
    {
        qDebug() << "agent's udp socket create error";
        return;
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(receive_gcs_control()));

    udpSocketSend = new QUdpSocket(this);
    // 设置目标端口
    peerPort = 5555;
    // 设置定时器，定时发送UAV自身的位置信息
    send_udp_timer = new QTimer(this);
    time_clac.start();
    // timer定时器触发自身timeout，绑定槽函数发送广播
    connect(send_udp_timer, SIGNAL(timeout()), this, SLOT(send_uav_data()));
}

UAVAgent::~UAVAgent()
{

}

void UAVAgent::init_control_status(int present_control_status)
{
    this->control_status = present_control_status;
}

void UAVAgent::set_start_pos(double lng, double lat)
{
    this->uav_lng = lng;
    this->uav_lat = lat;
    this->directionAngle = 45;
    this->speed = 0;
}

void UAVAgent::StartBtnClicked()
{
    if(!isStarted)
    {
        startBtn->setText(tr("Stop"));
        // 初始化内容，确定agent起始位置，后续可以继续更改逻辑
        // TODO
        set_start_pos(116.404, 39.917);
        init_control_status(0);
        send_udp_timer->start(update_time_period);
        isStarted = true;
    } else
    {
        startBtn->setText(tr("Start"));
        send_udp_timer->stop();
        isStarted = false;
    }
}

//void UAVAgent::update_uav_position()
//{

//}

//void UAVAgent::show_uav_position()
//{
//    QTimer *timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(update_uav_position()));
//    timer->start();

//}

void UAVAgent::send_uav_data()
{
    if(this->control_status == 1) {
        calculate_uav_coordinate_forward();
    } else if(this->control_status == 2) {
        calculate_uav_coordinate_backward();
    } else if(this->control_status == 3) {
        calculate_uav_coordinate_left();
    } else if(this->control_status == 4) {
        calculate_uav_coordinate_right();
    } else if(this->control_status == 5) {
        calculate_uav_coordinate_keep();
    } else {
        // Do nothing, means stop or pause
    }
    qDebug() << QString::number(uav_data.uav_lng, 'f', 6) << " , " << QString::number(uav_data.uav_lat, 'f', 6) << "\n";

    qDebug() << "send uav data to gcs";
    uav_data.uav_lat = this->uav_lat;
    uav_data.uav_lng = this->uav_lng;
    uav_data.uav_status = this->control_status;
    qDebug() << time_clac.elapsed();
    time_clac.restart();
    udpSocketSend->writeDatagram((char*)&uav_data, sizeof(uav_data), QHostAddress::Broadcast, peerPort);
    qDebug() << time_clac.elapsed();
    time_clac.restart();
}

void UAVAgent::receive_gcs_control()
{
    while(udpSocket->hasPendingDatagrams())
    {
        GCS_control datagram;
        udpSocket->readDatagram((char*)&datagram, sizeof(datagram));
        qDebug() << "received control data from GCS";
        qDebug() << datagram.control_direction;
        this->control_status = datagram.control_direction;
    }
}

void UAVAgent::calculate_uav_position(double direct_angle, double speed)
{
    double distance, distance_change_lng, distance_change_lat;
    // update_time_preriod: ms
    // speed: m/s
    distance = update_time_period * speed / 1000;
    distance_change_lng = distance * qSin(direct_angle * M_PI / 180);
    distance_change_lat = distance * qCos(direct_angle * M_PI / 180);
    this->uav_lat += distance_change_lat / (6371.393 * 1000);
    this->uav_lng += distance_change_lng / (6371.393 * 1000);
}


void UAVAgent::calculate_uav_coordinate_forward()
{
    // 暂时固定前向速度带来的效果是每次纬度 +0.000005(待修改)
    // 但是实际上我们应当明确前向带来的效果是对于当前移动方向的加速
    // 应当为对于按下按键到放开按键的时间计时，在该时间段内加速
    /*
    if(this->uav_lat < 90.0) {
        this->uav_lat += 0.000005;
    }
    */
    this->speed += 10;
    calculate_uav_position(this->directionAngle, this->speed);
}

void UAVAgent::calculate_uav_coordinate_backward()
{
    // 暂时固定后向速度带来的效果是每次纬度 -0.000005(待修改)
    // 但是实际上我们需要明确后向带来的效果是对于当前移动方向反方向的加速
    // 参考上述forward()内的表述
    /*
    if(this->uav_lat > -90.0) {
        this->uav_lat -= 0.000005;
    }
    */
    this->speed -= 5;
    calculate_uav_position(this->directionAngle, this->speed);
}

void UAVAgent::calculate_uav_coordinate_left()
{
    // 暂时固定右向速度带来的效果是每次经度 -0.000005(待修改)
    if(this->uav_lng < 180.0) {
        this->uav_lng -= 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_right()
{
    // 暂时固定右向速度带来的效果是每次经度 +0.000005(待修改)
    if(this->uav_lng > -180.0) {
        this->uav_lng += 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_keep()
{
    calculate_uav_position(this->directionAngle, this->speed);
}
