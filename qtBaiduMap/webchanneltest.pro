#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T08:16:23
#
#-------------------------------------------------

QT       += webenginewidgets webchannel
CONFIG   += c++11 console

TARGET = webchanneltest
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    previewpage.cpp \
    document.cpp \
    uavagent.cpp

HEADERS  += mainwidget.h \
    previewpage.h \
    document.h \
    uavagent.h

FORMS    += mainwidget.ui

RESOURCES += \
    webchanneltest.qrc

DISTFILES += \
    index.html \
    baiduMap.html
