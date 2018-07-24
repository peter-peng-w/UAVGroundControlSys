/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qwebengineview.h"
#include "widgetpfd.h"
#include "widgetsix.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QFrame *frame;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    WidgetPFD *widgetPFD;
    WidgetSix *widgetSix;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelLng;
    QLineEdit *lineEditLng;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelLat;
    QLineEdit *lineEditLat;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QWebEngineView *preview;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QStringLiteral("MainWidget"));
        MainWidget->resize(1162, 774);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(MainWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(472, 16777215));
        widget = new QWidget(frame);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(12, 12, 451, 731));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetPFD = new WidgetPFD(widget);
        widgetPFD->setObjectName(QStringLiteral("widgetPFD"));
        widgetPFD->setEnabled(true);
        widgetPFD->setMinimumSize(QSize(0, 0));
        widgetPFD->setMaximumSize(QSize(1000, 1000));

        verticalLayout_4->addWidget(widgetPFD);

        widgetSix = new WidgetSix(widget);
        widgetSix->setObjectName(QStringLiteral("widgetSix"));
        widgetSix->setMinimumSize(QSize(0, 0));
        widgetSix->setMaximumSize(QSize(1000, 1000));

        verticalLayout_4->addWidget(widgetSix);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelLng = new QLabel(widget);
        labelLng->setObjectName(QStringLiteral("labelLng"));

        horizontalLayout->addWidget(labelLng);

        lineEditLng = new QLineEdit(widget);
        lineEditLng->setObjectName(QStringLiteral("lineEditLng"));
        lineEditLng->setMaximumSize(QSize(84, 16777215));

        horizontalLayout->addWidget(lineEditLng);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelLat = new QLabel(widget);
        labelLat->setObjectName(QStringLiteral("labelLat"));

        horizontalLayout_2->addWidget(labelLat);

        lineEditLat = new QLineEdit(widget);
        lineEditLat->setObjectName(QStringLiteral("lineEditLat"));
        lineEditLat->setMaximumSize(QSize(84, 16777215));

        horizontalLayout_2->addWidget(lineEditLat);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);


        horizontalLayout_5->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_5);

        splitter->addWidget(frame);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        preview = new QWebEngineView(groupBox_2);
        preview->setObjectName(QStringLiteral("preview"));

        horizontalLayout_3->addWidget(preview);

        splitter->addWidget(groupBox_2);

        verticalLayout->addWidget(splitter);


        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", Q_NULLPTR));
        labelLng->setText(QApplication::translate("MainWidget", "Longitude", Q_NULLPTR));
        labelLat->setText(QApplication::translate("MainWidget", "Latitude   ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWidget", "Send", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWidget", "Right", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWidget", "start", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWidget", "Left", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWidget", "Up", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWidget", "Down", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWidget", "QTWebEnginePage", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
