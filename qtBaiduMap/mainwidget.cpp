#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "previewpage.h"
#include "document.h"
#include "uavagent.h"

#include <QFile>
#include <QWebChannel>
#include <QTimer>
#include <QString>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    PreviewPage *page = new PreviewPage(this);
    ui->preview->setPage(page);
    m_content.setUi(ui);

    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("content"), &m_content);
    page->setWebChannel(channel);

    ui->preview->setUrl(QUrl("qrc:/baiduMap.html"));

    ui->editor->setPlainText("hello...\n");
}

MainWidget::~MainWidget()
{
    delete ui;
}

bool MainWidget::isModified() const
{
    return ui->editor->document()->isModified();
}

void MainWidget::on_pushButton_clicked()
{
    // m_content.setSendTextText(ui->lineEditLng->text());
    m_content.setSendCoordinate(ui->lineEditLng->text(), ui->lineEditLat->text());
}


void MainWidget::update_and_show_uav_pos()
{
    uav_agent.set_start_pos(116.404, 39.917);
    uav_agent.init_control_status(0);
    uav_agent.show_uav_position();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_and_show_uav_pos_slot()));
    timer->start(100);
}

void MainWidget::update_and_show_uav_pos_slot()
{
    qDebug() << "Inside here";
    m_content.setSendCoordinate(QString::number(uav_agent.uav_lng, 'f', 6), QString::number(uav_agent.uav_lat, 'f', 6));
    qDebug() << "Have sent: " + QString::number(uav_agent.uav_lng, 'f', 6) + " , " + QString::number(uav_agent.uav_lat, 'f', 6) + "\n";
}

void MainWidget::on_pushButton_5_clicked()
{
    // Forward Button Clicked
    // 事实上此处应当通过该槽函数调用通信协议传递给Agent
    // 此处暂时不使用通信协议连接Agent与本地client之间的数据通信而是直接调用读取Agent的参数
    uav_agent.control_status = 1;
}

void MainWidget::on_pushButton_6_clicked()
{
    // Backward Button Clicked
    uav_agent.control_status = 2;
}

void MainWidget::on_pushButton_3_clicked()
{
    // Left Button Clicked
    uav_agent.control_status = 3;
}

void MainWidget::on_pushButton_4_clicked()
{
    // Right Button Clicked
    uav_agent.control_status = 4;
}

void MainWidget::on_pushButton_2_clicked()
{
    // Stop Button Clicked
    uav_agent.control_status = 0;
}
