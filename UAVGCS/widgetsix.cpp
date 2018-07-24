#ifndef WIDGETSIX_CPP
#define WIDGETSIX_CPP
#endif

#include "widgetsix.h"
#include "ui_widgetsix.h"

WidgetSix::WidgetSix(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetSix),
    m_widgetADI ( 0 ),
    m_widgetALT ( 0 ),
    m_widgetASI ( 0 ),
    m_widgetHSI ( 0 ),
    m_widgetTC  ( 0 ),
    m_widgetVSI ( 0 )
{
    m_ui->setupUi(this);

    m_widgetADI = m_ui->widgetADI;
    m_widgetALT = m_ui->widgetALT;
    m_widgetASI = m_ui->widgetASI;
    m_widgetHSI = m_ui->widgetHSI;
    m_widgetTC  = m_ui->widgetTC;
    m_widgetVSI = m_ui->widgetVSI;
}

WidgetSix::~WidgetSix()
{
     if ( m_ui ) delete m_ui; m_ui = 0;
}

void WidgetSix::update()
{
    m_ui->widgetADI->update();
    m_ui->widgetALT->update();
    m_ui->widgetASI->update();
    m_ui->widgetHSI->update();
    m_ui->widgetTC->update();
    m_ui->widgetVSI->update();
}


