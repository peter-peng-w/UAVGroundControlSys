#include "document.h"
#include "mainwidget.h"
#include "uavagent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    // UAVAgent uav_agent;
    // uav_agent.show_uav_position();
    w.update_and_show_uav_pos();
    return a.exec();
}
