#ifndef WIDGETVSI_CPP
#define WIDGETVSI_CPP
#endif

#include "widgetvsi.h"
#include "ui_widgetvsi.h"

WidgetVSI::WidgetVSI(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::WidgetVSI),
    m_vsi(0),
    m_layoutSq(0)
{
    m_ui->setupUi(this);
    setupUi();
    m_vsi = m_ui->graphicsVSI;
}

WidgetVSI::~WidgetVSI()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}

void WidgetVSI::setupUi()
{
    m_layoutSq = new LayoutSquare( this );

    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsVSI );

    setLayout( m_layoutSq );
}
