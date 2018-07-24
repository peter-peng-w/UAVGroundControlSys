#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "document.h"

#include <QWidget>
#include <QString>
#include <QtNetwork/QUdpSocket>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "uavagent.h"

#define BYTE unsigned char

namespace Ui {
class MainWidget;
}

#pragma pack(1)
struct UAV_data {
    double uav_lng;
    double uav_lat;
    float uav_direction_angle;
    float speed;
    float altitude;
    float pitch;
    float yaw;
    float roll;
    int uav_status;
};
struct GCS_control {
    int control_direction;
    // double change_degree;
};
#pragma pack()

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void update_and_show_uav_pos();
    void setPFD();
//public Q_SLOTS:
//    void setEnabled(bool);

public slots:
    // void update_and_show_uav_pos_slot();
    void send_gcs_control();    // 槽函数，传输GCS本地发送的控制指令数据报GCS_control
    void receive_uav_data();    // 槽函数，接收从UAVgent传输过来的远端uav数据报UAV_data

private slots:
    void on_pushButton_clicked();

    // void on_pushButton_5_clicked();
    // up
    void on_pushButton_5_pressed();
    void on_pushButton_5_released();

    // down
    // void on_pushButton_6_clicked();
    void on_pushButton_6_pressed();
    void on_pushButton_6_released();

    // left
    // void on_pushButton_3_clicked();
    void on_pushButton_3_pressed();
    void on_pushButton_3_released();

    // right
    // void on_pushButton_4_clicked();
    void on_pushButton_4_pressed();
    void on_pushButton_4_released();

    // start
    void on_pushButton_2_clicked();

private:
    bool isModified() const;
    bool isStarted;
    bool isSuccessBind;
    int myPort;
    int peerPort;
    QUdpSocket *udpSocket;
    UAV_data uav_data;
    GCS_control gcs_control;
    Ui::MainWidget *ui;
    Document m_content;

    // UAVAgent uav_agent; // not used anymore, replaced by independent agent

    // about QFlightInstrument,
    // used to randomly generate value of all kinds of paras
    int m_timerId;
    int m_steps;
    float m_realTime;
    QTime m_time;
};

#endif // MAINWIDGET_H
