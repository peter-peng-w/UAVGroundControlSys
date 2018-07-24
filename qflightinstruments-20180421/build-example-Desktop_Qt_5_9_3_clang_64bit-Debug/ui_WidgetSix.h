/********************************************************************************
** Form generated from reading UI file 'WidgetSix.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETSIX_H
#define UI_WIDGETSIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "widgetadi.h"
#include "widgetalt.h"
#include "widgetasi.h"
#include "widgethsi.h"
#include "widgettc.h"
#include "widgetvsi.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetSix
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    WidgetASI *widgetASI;
    WidgetADI *widgetADI;
    WidgetALT *widgetALT;
    WidgetTC *widgetTC;
    WidgetHSI *widgetHSI;
    WidgetVSI *widgetVSI;

    void setupUi(QWidget *WidgetSix)
    {
        if (WidgetSix->objectName().isEmpty())
            WidgetSix->setObjectName(QStringLiteral("WidgetSix"));
        WidgetSix->resize(400, 300);
        gridLayout_2 = new QGridLayout(WidgetSix);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetASI = new WidgetASI(WidgetSix);
        widgetASI->setObjectName(QStringLiteral("widgetASI"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetASI->sizePolicy().hasHeightForWidth());
        widgetASI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetASI, 0, 0, 1, 1);

        widgetADI = new WidgetADI(WidgetSix);
        widgetADI->setObjectName(QStringLiteral("widgetADI"));
        sizePolicy.setHeightForWidth(widgetADI->sizePolicy().hasHeightForWidth());
        widgetADI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetADI, 0, 1, 1, 1);

        widgetALT = new WidgetALT(WidgetSix);
        widgetALT->setObjectName(QStringLiteral("widgetALT"));
        sizePolicy.setHeightForWidth(widgetALT->sizePolicy().hasHeightForWidth());
        widgetALT->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetALT, 0, 2, 1, 1);

        widgetTC = new WidgetTC(WidgetSix);
        widgetTC->setObjectName(QStringLiteral("widgetTC"));
        sizePolicy.setHeightForWidth(widgetTC->sizePolicy().hasHeightForWidth());
        widgetTC->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetTC, 1, 0, 1, 1);

        widgetHSI = new WidgetHSI(WidgetSix);
        widgetHSI->setObjectName(QStringLiteral("widgetHSI"));
        sizePolicy.setHeightForWidth(widgetHSI->sizePolicy().hasHeightForWidth());
        widgetHSI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetHSI, 1, 1, 1, 1);

        widgetVSI = new WidgetVSI(WidgetSix);
        widgetVSI->setObjectName(QStringLiteral("widgetVSI"));
        sizePolicy.setHeightForWidth(widgetVSI->sizePolicy().hasHeightForWidth());
        widgetVSI->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widgetVSI, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WidgetSix);

        QMetaObject::connectSlotsByName(WidgetSix);
    } // setupUi

    void retranslateUi(QWidget *WidgetSix)
    {
        WidgetSix->setWindowTitle(QApplication::translate("WidgetSix", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetSix: public Ui_WidgetSix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETSIX_H
