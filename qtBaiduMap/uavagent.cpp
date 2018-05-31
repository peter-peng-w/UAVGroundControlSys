#include "uavagent.h"
#include <QTimer>
#include <QString>
#include <QDebug>

UAVAgent::UAVAgent(QObject *parent) : QObject(parent)
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
    // m_point.sendCoordinate(QString::number(this->uav_lng, 'f', 6), QString::number(this->uav_lat, 'f', 6));
    // this->uav_lat += 0.0001;
    // this->uav_lng += 0.0001;
    if(this->control_status == 1) {
        calculate_uav_coordinate_forward();
    } else if(this->control_status == 2) {
        calculate_uav_coordinate_backward();
    } else if(this->control_status == 3) {
        calculate_uav_coordinate_left();
    } else if(this->control_status == 4) {
        calculate_uav_coordinate_right();
    } else {
        // Do nothing
    }
    qDebug() << QString::number(this->uav_lng, 'f', 6) << " , " << QString::number(this->uav_lat, 'f', 6) << "\n";
}

void UAVAgent::show_uav_position()
{
    qDebug() << "Inside agent";
    // this->uav_lng = 116.404;
    // this->uav_lat = 39.9171;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_uav_position()));
    timer->start(100);
}

void UAVAgent::calculate_uav_coordinate_forward()
{
    // 暂时固定前向速度带来的效果是每次纬度 +0.000001
    // 但是实际上我们应当明确前向带来的效果是对于当前移动方向的加速
    // 应当为对于按下按键到放开按键的时间计时，在该时间段内加速
    if(this->uav_lat < 90.0) {
        this->uav_lat += 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_backward()
{
    // 暂时固定后向速度带来的效果是每次纬度 -0.000001
    // 但是实际上我们需要明确后向带来的效果是对于当前移动方向反方向的加速
    // 参考上述forward()内的表述
    if(this->uav_lat > -90.0) {
        this->uav_lat -= 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_left()
{
    // 暂时固定右向速度带来的效果是每次经度 -0.000001
    if(this->uav_lng < 180.0) {
        this->uav_lng -= 0.000005;
    }
}

void UAVAgent::calculate_uav_coordinate_right()
{
    // 暂时固定右向速度带来的效果是每次经度 +0.000001
    if(this->uav_lng > -180.0) {
        this->uav_lng += 0.000005;
    }
}
