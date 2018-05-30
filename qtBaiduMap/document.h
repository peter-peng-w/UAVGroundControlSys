/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QString>
#include "ui_mainwidget.h"

namespace Ui {
class MainWidget;
}

class Document : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER s_text NOTIFY sendText)
    Q_PROPERTY(QString textLongitude MEMBER lng_text NOTIFY sendCoordinate)
    Q_PROPERTY(QString textLatitude MEMBER lat_text NOTIFY sendCoordinate)

public:
    explicit Document(QObject *parent = nullptr) : QObject(parent) {}

    void setSendTextText(const QString &text);
    void setSendCoordinate(const QString &textLongitude, const QString &textLatitude);
    void setUi(Ui::MainWidget *ui);

public slots:
    void receiveText(const QString &r_text);

signals:
    void sendText(const QString &text);
    void sendCoordinate(const QString &textLongitude, const QString &textLatitude);

private:
    void displayMessage(const QString &message);
    QString s_text;
    QString lng_text;
    QString lat_text;
    QString recieve_text;
    Ui::MainWidget *mainUi;
};

#endif // DOCUMENT_H
