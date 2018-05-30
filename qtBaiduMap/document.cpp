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

#include "document.h"


void Document::setSendTextText(const QString &text)
{
    s_text = text;
    emit sendText(s_text);
}

void Document::setSendCoordinate(const QString &textLongitude, const QString &textLatitude)
{
    lng_text = textLongitude;
    lat_text = textLatitude;
    emit sendCoordinate(lng_text, lat_text);
}

void Document::displayMessage(const QString &message)
{
      mainUi->editor->appendPlainText(message);
}

/*!
    This slot is invoked from the HTML client side and the text displayed on the server side.
*/
void Document::receiveText(const QString &r_text)
{
    displayMessage(QObject::tr("Received message: %1").arg(r_text));
}

void Document::setUi(Ui::MainWidget *ui)
{
    mainUi = ui;
}
