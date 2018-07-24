#ifndef WIDGETSIX_H
#define WIDGETSIX_H

#include <QWidget>

#include "widgetadi.h"
#include "widgetalt.h"
#include "widgetasi.h"
#include "widgethsi.h"
#include "widgettc.h"
#include "widgetvsi.h"

namespace Ui {
class WidgetSix;
}

class WidgetSix : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSix(QWidget *parent = 0);
    ~WidgetSix();
    void update();

    inline void setRoll( float roll )
    {
        m_widgetADI->setRoll( roll );
    }

    inline void setPitch( float pitch )
    {
        m_widgetADI->setPitch( pitch );
    }

    inline void setAltitude( float altitude )
    {
        m_widgetALT->setAltitude( altitude );
    }

    inline void setPressure( float pressure )
    {
        m_widgetALT->setPressure( pressure );
    }

    inline void setAirspeed( float airspeed )
    {
        m_widgetASI->setAirspeed( airspeed );
    }

    inline void setHeading( float heading )
    {
        m_widgetHSI->setHeading( heading );
    }

    inline void setTurnRate( float turnRate )
    {
        m_widgetTC->setTurnRate( turnRate );
    }

    inline void setSlipSkid( float slipSkid )
    {
        m_widgetTC->setSlipSkid( slipSkid );
    }

    inline void setClimbRate( float climbRate )
    {
        m_widgetVSI->setClimbRate( climbRate );
    }

private:
    Ui::WidgetSix   *m_ui;

    WidgetADI       *m_widgetADI;
    WidgetALT       *m_widgetALT;
    WidgetASI       *m_widgetASI;
    WidgetHSI       *m_widgetHSI;
    WidgetTC        *m_widgetTC;
    WidgetVSI       *m_widgetVSI;
};

#endif // WIDGETSIX_H
