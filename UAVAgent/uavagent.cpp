#include "uavagent.h"
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QHostAddress>
#include <QUdpSocket>

UAVAgent::UAVAgent(QObject *parent) : QObject(parent)
{
    // init
    uav_data.uav_lat = 0.000;
    uav_data.uav_lng = 0.000;
    uav_data.uav_status = 0;

    qDebug() << "agent build success... data size:";
    qDebug() << sizeof(uav_data);
    qDebug() << "\n";

    udpSocket = new QUdpSocket(this);

    myPort = 3355;
    isSuccessBind = udpSocket->bind(myPort);
    if(!isSuccessBind)
    {
        qDebug() << "agent's udp socket create error";
        return;
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(receive_gcs_control()));

    // 设置目标端口
    peerPort = 5555;
    // 设置定时器，定时发送UAV自身的位置信息
    timer = new QTimer(this);
    timer->start(100);
    // timer定时器触发自身timeout，绑定槽函数发送广播
    connect(timer, SIGNAL(timeout()), this, SLOT(send_uav_data()));
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
}

void UAVAgent::update_uav_position()
{
    if(this->control_status == 1) {
        calculate_uav_coordinate_forward();
    } else if(this->control_status == 2) {
        calculate_uav_coordinate_backward();
    } else if(this->control_status == 3) {
        calculate_uav_coordinate_left();
    } else if(this->control_status == 4) {
        calculate_uav_coordinate_right();
    } else {
        // Do nothing, means stop or pause
    }
    qDebug() << QString::number(this->uav_lng, 'f', 6) << " , " << QString::number(this->uav_lat, 'f', 6) << "\n";
}

void UAVAgent::show_uav_position()
{
    qDebug() << "Inside agent";
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_uav_position()));
    timer->start(100);
}

void UAVAgent::send_uav_data()
{
    udpSocket->writeDatagram((char*)&uav_data, sizeof(uav_data), QHostAddress::Broadcast, peerPort);
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

void UAVAgent::calculate_uav_coordinate_forward()
{
    // 暂时固定前向速度带来的效果是每次纬度 +0.000005(待修改)
    // 但是实际上我们应当明确前向带来的效果是对于当前移动方向的加速
    // 应当为对于按下按键到放开按键的时间计时，在该时间段内加速
    if(this->uav_lat < 90.0) {
        this->uav_lat += 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_backward()
{
    // 暂时固定后向速度带来的效果是每次纬度 -0.000005(待修改)
    // 但是实际上我们需要明确后向带来的效果是对于当前移动方向反方向的加速
    // 参考上述forward()内的表述
    if(this->uav_lat > -90.0) {
        this->uav_lat -= 0.000005;
    }
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
