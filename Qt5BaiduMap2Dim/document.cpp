#include "document.h"

void Document::sendText(const QString &text)
{
    s_text = text;
    emit sendText(s_text);
}

void Document::displayMessage(const QString &message)
{
    mainUi->editor->appendPlainText(message);
}

/*
 *  This slot is invoked from the HTML client and the text displayed on the server side.
 */
void Document::receiveText(const QString &r_text)
{
    displayMessage(QObject::tr("Received message: %1").arg(r_text));
}

void Document::setUi(Ui::MainWindow *ui)
{
    mainUi = ui;
}
