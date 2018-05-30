#include "uavagent.h"
#include <QTimer>
#include <QString>
#include <QDebug>

UAVAgent::UAVAgent(QObject *parent) : QObject(parent)
{

}

void UAVAgent::set_start_pos(double lng, double lat)
{
    this->uav_lng = lng;
    this->uav_lat = lat;
}

void UAVAgent::update_uav_position()
{
    // m_point.sendCoordinate(QString::number(this->uav_lng, 'f', 6), QString::number(this->uav_lat, 'f', 6));
    this->uav_lat += 0.0001;
    this->uav_lng += 0.0001;
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
