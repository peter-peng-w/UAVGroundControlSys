/********************************************************************************
** Form generated from reading UI file 'WidgetVSI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETVSI_H
#define UI_WIDGETVSI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_VSI.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetVSI
{
public:
    qfi_VSI *graphicsVSI;

    void setupUi(QWidget *WidgetVSI)
    {
        if (WidgetVSI->objectName().isEmpty())
            WidgetVSI->setObjectName(QStringLiteral("WidgetVSI"));
        WidgetVSI->resize(400, 300);
        graphicsVSI = new qfi_VSI(WidgetVSI);
        graphicsVSI->setObjectName(QStringLiteral("graphicsVSI"));
        graphicsVSI->setEnabled(false);
        graphicsVSI->setGeometry(QRect(70, 50, 256, 192));
        graphicsVSI->setFrameShape(QFrame::NoFrame);
        graphicsVSI->setFrameShadow(QFrame::Plain);
        graphicsVSI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsVSI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsVSI->setInteractive(false);

        retranslateUi(WidgetVSI);

        QMetaObject::connectSlotsByName(WidgetVSI);
    } // setupUi

    void retranslateUi(QWidget *WidgetVSI)
    {
        WidgetVSI->setWindowTitle(QApplication::translate("WidgetVSI", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetVSI: public Ui_WidgetVSI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETVSI_H
