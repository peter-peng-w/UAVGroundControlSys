#ifndef UAVAGENT_H
#define UAVAGENT_H

#include <QObject>
#include <QString>
#include "document.h"

class UAVAgent : public QObject
{
    Q_OBJECT
public:
    explicit UAVAgent(QObject *parent = nullptr);
    double uav_lat;            // uav所在位置的纬度
    double uav_lng;            // uav所在位置的经度
    // 注：百度地图的经纬度精度为小数点后六位，这里暂时不考虑真实经纬度(国际标准)与百度地图(国内标准)的经纬度之间的换算

    double anglePitch;         // 俯仰角           绕Xb轴转过的角度
    double angleYaw;           // 航向角(偏航角)    绕Zb轴转过的角度
    double angleRoll;          // 横滚角           绕Yb轴转过的角度
    // 注：考虑机体坐标系为右手系，即横穿机翼的为Xb轴，纵贯机身的为Yb轴，垂直的重力线为Zb轴

    double speed;                       // 对地速度
    double altitude;                    // 高度
    double accelerateSpeedAdd;          // 正向加速度
    double accelerateSpeedReduce;       // 反向加速度
    double leftDirectionChangeAngle;    // 向左转弯时候以该角速度改变横滚角至某一特定的最大横滚角值以及复原
    double rightDirectionChangeAngle;   // 向右转弯时候以该角速度改变横滚角至某一特定的最大横滚角值以及复原

public:
    void calculate_uav_coordinate_forward();
    void calculate_uav_coordinate_backward();
    void calculate_uav_coordinate_left();
    void calculate_uav_coordinate_right();
    void show_uav_position();
    void set_start_pos(double lng, double lat);

signals:

public slots:
    void update_uav_position();

private:
    Document m_point;
};

#endif // UAVAGENT_H
