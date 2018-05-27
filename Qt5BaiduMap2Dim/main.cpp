#include "mainwindow.h"
#include <QApplication>
#include <QtWebEngineWidgets>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    // Qt高DPI支持
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.resize(QSize(1024, 768));
//    QWebEngineView view;
//    view.setUrl(QUrl(QStringLiteral("http://www.baidu.com")));
//    view.resize(1024, 768);
//    view.show();
    return a.exec();
}
