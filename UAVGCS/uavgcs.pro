#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T08:16:23
#
#-------------------------------------------------

QT       += webenginewidgets webchannel network core gui svg
CONFIG   += c++11 console

TARGET = UAVGCS
TEMPLATE = app

INCLUDEPATH += ./ ./qfi

SOURCES += main.cpp\
        mainwidget.cpp \
    previewpage.cpp \
    document.cpp \
    uavagent.cpp \
    qfi/qfi_ADI.cpp \
    qfi/qfi_ALT.cpp \
    qfi/qfi_ASI.cpp \
    qfi/qfi_HSI.cpp \
    qfi/qfi_NAV.cpp \
    qfi/qfi_PFD.cpp \
    qfi/qfi_TC.cpp \
    qfi/qfi_VSI.cpp \
    LayoutSquare.cpp \
    widgetpfd.cpp \
    widgetasi.cpp \
    widgetadi.cpp \
    widgetalt.cpp \
    widgettc.cpp \
    widgethsi.cpp \
    widgetvsi.cpp \
    widgetsix.cpp

HEADERS  += mainwidget.h \
    previewpage.h \
    document.h \
    uavagent.h \
    qfi/qfi_ADI.h \
    qfi/qfi_ALT.h \
    qfi/qfi_ASI.h \
    qfi/qfi_HSI.h \
    qfi/qfi_NAV.h \
    qfi/qfi_PFD.h \
    qfi/qfi_TC.h \
    qfi/qfi_VSI.h \
    LayoutSquare.h \
    widgetpfd.h \
    widgetasi.h \
    widgetadi.h \
    widgetalt.h \
    widgettc.h \
    widgethsi.h \
    widgetvsi.h \
    widgetsix.h

FORMS    += mainwidget.ui \
    widgetpfd.ui \
    widgetasi.ui \
    widgetadi.ui \
    widgetalt.ui \
    widgettc.ui \
    widgethsi.ui \
    widgetvsi.ui \
    widgetsix.ui

RESOURCES += \
    webchanneltest.qrc \
    qfi/qfi.qrc

DISTFILES += \
    index.html \
    baiduMap.html

UI_DIR = ./UI
