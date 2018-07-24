#ifndef WIDGETASI_CPP
#define WIDGETASI_CPP
#endif

#include "widgetasi.h"
#include "ui_widgetasi.h"

WidgetASI::WidgetASI( QWidget *parent ) :
    QWidget( parent ),
    m_ui( new Ui::WidgetASI ),
    m_asi( 0 ),
    m_layoutSq( 0 )
{
    m_ui->setupUi(this);
    setupUi();
    m_asi = m_ui->graphicsASI;
}

WidgetASI::~WidgetASI()
{
    if ( m_layoutSq ) delete m_layoutSq; m_layoutSq = 0;

    if ( m_ui ) delete m_ui; m_ui = 0;
}

void WidgetASI::setupUi()
{
    m_layoutSq = new LayoutSquare( this );
    m_layoutSq->setContentsMargins( 0, 0, 0, 0 );
    m_layoutSq->addWidget( m_ui->graphicsASI );

    setLayout(m_layoutSq);
}
