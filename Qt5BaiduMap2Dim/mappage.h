#ifndef MAPPAGE_H
#define MAPPAGE_H

#include <QWebEnginePage>
#include <QWebChannel>

class MapPage : public QWebEnginePage
{
    Q_OBJECT
public:
    explicit MapPage(QObject * parent = nullptr) : QWebEnginePage(parent) {}

protected:
    bool acceptNavigationRequest(const QUrl &url, NavigationType type, bool isMainFrame);
};

#endif // MAPPAGE_H
