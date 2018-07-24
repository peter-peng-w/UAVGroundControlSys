#ifndef WIDGETTC_H
#define WIDGETTC_H

#include <QWidget>
#include <qfi_TC.h>
#include "LayoutSquare.h"

namespace Ui {
class WidgetTC;
}

class WidgetTC : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetTC(QWidget *parent = 0);
    ~WidgetTC();
    inline void update()
    {
        m_tc->update();
    }

    inline void setTurnRate( float turnRate )
    {
        m_tc->setTurnRate( turnRate );
    }

    inline void setSlipSkid( float slipSkid )
    {
        m_tc->setSlipSkid( slipSkid );
    }

private:
    Ui::WidgetTC *m_ui;
    qfi_TC       *m_tc;
    LayoutSquare *m_layoutSq;

    void setupUi();
};

#endif // WIDGETTC_H
