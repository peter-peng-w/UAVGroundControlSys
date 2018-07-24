/********************************************************************************
** Form generated from reading UI file 'WidgetNAV.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETNAV_H
#define UI_WIDGETNAV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_NAV.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetNAV
{
public:
    QFrame *frameNAV;
    QGridLayout *gridLayout;
    qfi_NAV *graphicsNAV;

    void setupUi(QWidget *WidgetNAV)
    {
        if (WidgetNAV->objectName().isEmpty())
            WidgetNAV->setObjectName(QStringLiteral("WidgetNAV"));
        WidgetNAV->resize(400, 400);
        frameNAV = new QFrame(WidgetNAV);
        frameNAV->setObjectName(QStringLiteral("frameNAV"));
        frameNAV->setGeometry(QRect(70, 70, 260, 260));
        frameNAV->setStyleSheet(QLatin1String("#frameNAV\n"
"{\n"
"	background-color: #000;\n"
"	border-radius: 10px;\n"
"}"));
        frameNAV->setFrameShape(QFrame::StyledPanel);
        frameNAV->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameNAV);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        graphicsNAV = new qfi_NAV(frameNAV);
        graphicsNAV->setObjectName(QStringLiteral("graphicsNAV"));
        graphicsNAV->setEnabled(false);
        graphicsNAV->setFocusPolicy(Qt::NoFocus);
        graphicsNAV->setFrameShape(QFrame::NoFrame);
        graphicsNAV->setFrameShadow(QFrame::Plain);
        graphicsNAV->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsNAV->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsNAV->setInteractive(false);
        graphicsNAV->setOptimizationFlags(QGraphicsView::IndirectPainting);

        gridLayout->addWidget(graphicsNAV, 0, 0, 1, 1);


        retranslateUi(WidgetNAV);

        QMetaObject::connectSlotsByName(WidgetNAV);
    } // setupUi

    void retranslateUi(QWidget *WidgetNAV)
    {
        WidgetNAV->setWindowTitle(QApplication::translate("WidgetNAV", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetNAV: public Ui_WidgetNAV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETNAV_H
