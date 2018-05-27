#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QWebEngineView(this);
    view->load(QUrl::fromLocalFile("/Users/wangp/MyProgram/GraduateProject/UAVGroundControlSys/resources/baiduMap.html"));
    view->show();

//    QWebEngineView view;
//    view.setUrl(QUrl(QStringLiteral("http://www.baidu.com")));
//    view.resize(1024, 768);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    view->resize(this->size());
}
