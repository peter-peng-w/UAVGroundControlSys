#ifndef WIDGETALT_H
#define WIDGETALT_H

#include <QWidget>
#include <qfi_ALT.h>
#include "LayoutSquare.h"

namespace Ui {
class WidgetALT;
}

class WidgetALT : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetALT(QWidget *parent = 0);
    ~WidgetALT();
    inline void update()
    {
        m_alt->update();
    }

    inline void setAltitude( float altitude )
    {
        m_alt->setAltitude( altitude );
    }

    inline void setPressure( float pressure )
    {
        m_alt->setPressure( pressure );
    }

private:
    Ui::WidgetALT   *m_ui;
    qfi_ALT         *m_alt;
    LayoutSquare    *m_layoutSq;

    void setupUi();
};

#endif // WIDGETALT_H
