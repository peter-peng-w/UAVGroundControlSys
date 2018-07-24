/********************************************************************************
** Form generated from reading UI file 'WidgetTC.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETTC_H
#define UI_WIDGETTC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_TC.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetTC
{
public:
    qfi_TC *graphicsTC;

    void setupUi(QWidget *WidgetTC)
    {
        if (WidgetTC->objectName().isEmpty())
            WidgetTC->setObjectName(QStringLiteral("WidgetTC"));
        WidgetTC->resize(400, 300);
        graphicsTC = new qfi_TC(WidgetTC);
        graphicsTC->setObjectName(QStringLiteral("graphicsTC"));
        graphicsTC->setEnabled(false);
        graphicsTC->setGeometry(QRect(60, 40, 256, 192));
        graphicsTC->setFrameShape(QFrame::NoFrame);
        graphicsTC->setFrameShadow(QFrame::Plain);
        graphicsTC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsTC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsTC->setInteractive(false);

        retranslateUi(WidgetTC);

        QMetaObject::connectSlotsByName(WidgetTC);
    } // setupUi

    void retranslateUi(QWidget *WidgetTC)
    {
        WidgetTC->setWindowTitle(QApplication::translate("WidgetTC", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetTC: public Ui_WidgetTC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETTC_H
