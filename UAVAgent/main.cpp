#include "uavagent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UAVAgent w;
    w.show();

    return a.exec();
}
