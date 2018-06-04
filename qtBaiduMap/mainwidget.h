#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "document.h"

#include <QWidget>
#include <QString>
#include <QtNetwork/QUdpSocket>
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
//public Q_SLOTS:
//    void setEnabled(bool);

public slots:
    void update_and_show_uav_pos_slot();
    void send_gcs_control();    // 槽函数，传输GCS本地发送的控制指令数据报GCS_control
    void receive_uav_data();    // 槽函数，接收从UAVgent传输过来的远端uav数据报UAV_data

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

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
    UAVAgent uav_agent;
};

#endif // MAINWIDGET_H
