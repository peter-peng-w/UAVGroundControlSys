#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>
#include <QString>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class Document : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER s_text NOTIFY sendText)

public:
    explicit Document(QObject *parent = nullptr) : QObject(parent) {}
    void setSendText(const QString &text);
    void setUi(Ui::MainWindow *ui);

signals:
    void sendText(const QString &text);

public slots:
    void receiveText(const QString &r_text);

private:
    void displayMessage(const QString &message);
    QString s_text;
    QString receive_text;
    Ui::MainWindow *mainUi;
};

#endif // DOCUMENT_H
