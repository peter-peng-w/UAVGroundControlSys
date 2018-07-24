#ifndef WIDGETTC_CPP
#define WIDGETTC_CPP
#endif

#include "widgettc.h"
#include "ui_widgettc.h"

WidgetTC::WidgetTC(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetTC),
    m_tc(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_tc = m_ui->graphicsTC;
}

WidgetTC::~WidgetTC()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;
    if ( m_ui ) delete m_ui; m_ui = 0;
}

void WidgetTC::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsTC );

    setLayout( m_layoutSq );
}
