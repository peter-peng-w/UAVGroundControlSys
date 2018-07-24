#ifndef WIDGETALT_CPP
#define WIDGETALT_CPP
#endif

#include "widgetalt.h"
#include "ui_widgetalt.h"

WidgetALT::WidgetALT(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetALT),
    m_alt(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_alt = m_ui->graphicsALT;
}

WidgetALT::~WidgetALT()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;
    if ( m_ui ) delete m_ui; m_ui = 0;
}


void WidgetALT::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsALT );

    setLayout( m_layoutSq );
}
