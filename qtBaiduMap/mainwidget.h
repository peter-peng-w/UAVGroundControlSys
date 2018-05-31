#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "document.h"

#include <QWidget>
#include <QString>
#include "uavagent.h"

namespace Ui {
class MainWidget;
}

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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    //void on_pushButton_forward_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    bool isModified() const;

    Ui::MainWidget *ui;
    Document m_content;
    UAVAgent uav_agent;
};

#endif // MAINWIDGET_H
