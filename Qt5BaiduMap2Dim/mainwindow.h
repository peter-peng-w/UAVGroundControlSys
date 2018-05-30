#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "document.h"

#include <QMainWindow>
#include <QtWebEngineWidgets>
#include <QWebEngineView>
#include <QWidget>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView* view;
    Document m_content;
    bool isModified() const;
};

#endif // MAINWINDOW_H
