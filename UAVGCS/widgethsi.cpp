#ifndef WIDGETHSI_CPP
#define WIDGETHSI_CPP
#endif

#include "widgethsi.h"
#include "ui_widgethsi.h"

WidgetHSI::WidgetHSI(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetHSI),
    m_hsi(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_hsi = m_ui->graphicsHSI;
}

WidgetHSI::~WidgetHSI()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}

void WidgetHSI::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsHSI );

    setLayout( m_layoutSq );
}
