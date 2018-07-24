#ifndef WIDGETASI_H
#define WIDGETASI_H

#include <QWidget>
#include <qfi_ASI.h>
#include "LayoutSquare.h"

namespace Ui {
class WidgetASI;
}

class WidgetASI : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetASI(QWidget *parent = 0);
    ~WidgetASI();
    inline void update()
    {
        m_asi->update();
    }
    inline void setAirspeed( float airspeed )
    {
        m_asi->setAirspeed( airspeed );
    }

private:
    Ui::WidgetASI   *m_ui;
    qfi_ASI         *m_asi;
    LayoutSquare    *m_layoutSq;

    void setupUi();
};

#endif // WIDGETASI_H
