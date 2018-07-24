#ifndef UAVAGENT_H
#define UAVAGENT_H

#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>
#include <QPushButton>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>

#define BYTE unsigned char

#pragma pack(1)
struct UAV_data {
    double uav_lng;
    double uav_lat;
    int uav_status;
};
struct GCS_control {
    int control_direction;
    // double change_degree;
};
#pragma pack()

class UAVAgent : public QWidget
{
    Q_OBJECT

public:
    // explicit UAVAgent(QObject *parent = nullptr);
    UAVAgent(QWidget *parent = 0);
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

    // 通过该参数模拟通信协议里面所包含的指令数据段
    // 1->forward  2->backward  3->left  4->right  0[else]->stop
    int control_status;
    ~UAVAgent();

public:
    void calculate_uav_coordinate_forward();
    void calculate_uav_coordinate_backward();
    void calculate_uav_coordinate_left();
    void calculate_uav_coordinate_right();
    void show_uav_position();
    void init_control_status(int present_control_status);
    void set_start_pos(double lng, double lat);


signals:

public slots:
    void update_uav_position();
    void send_uav_data();
    void receive_gcs_control();
    void StartBtnClicked();


private:
    QPushButton *startBtn;
    QVBoxLayout *mainLayout;
    int port;
    int myPort;
    int peerPort;
    bool isStarted;
    bool isSuccessBind;
    QUdpSocket *udpSocket;
    QTimer *send_udp_timer;
    QTimer *update_uav_timer;
    UAV_data uav_data;
};

#endif // UAVAGENT_H
