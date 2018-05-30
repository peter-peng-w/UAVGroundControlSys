#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mappage.h"

#include <QWebChannel>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QtWebEngineWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // view = new QWebEngineView(this);
    // view->load(QUrl("qrc:/resources/baiduMap.html"));
    // view->show();
    // ui->mapWidget->setUrl(QUrl("qrc:/resources/baiduMap.html"));
    MapPage *myMapPage = new MapPage(this);
    ui->preview->setPage(myMapPage);

    QWebChannel *myChannel = new QWebChannel(this);
    myChannel->registerObject(QStringLiteral("content"), &m_content);
    myMapPage->setWebChannel(myChannel);

    ui->preview->setUrl(QUrl("qrc:/resources/baiduMap.html"));

    ui->editor->setPlainText("hello...\n");

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

void MainWindow::on_pushButton_clicked()
{
    m_content.setSendText(ui->lineEdit->text());
}

bool MainWindow::isModified() const
{
    return ui->editor->document()->isModified();
}
