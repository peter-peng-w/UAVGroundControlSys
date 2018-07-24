#ifndef WIDGETVSI_H
#define WIDGETVSI_H

#include <QWidget>
#include <qfi_VSI.h>
#include "LayoutSquare.h"

namespace Ui {
class WidgetVSI;
}

class WidgetVSI : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetVSI(QWidget *parent = 0);
    ~WidgetVSI();

    inline void update()
    {
        m_vsi->update();
    }

    inline void setClimbRate( float climbRate )
    {
        m_vsi->setClimbRate( climbRate );
    }

private:
    Ui::WidgetVSI *m_ui;
    qfi_VSI       *m_vsi;
    LayoutSquare  *m_layoutSq;

    void setupUi();
};

#endif // WIDGETVSI_H
