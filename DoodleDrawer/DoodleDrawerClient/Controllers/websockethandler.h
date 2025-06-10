#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QtWebSockets>

class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();

    Q_INVOKABLE void connectToServer(QString hostAddress);

public slots:
    void onConnected();
    void onTextMessageReceived(QString);
signals:
private:
    QWebSocket *m_webSocket;
};

#endif // WEBSOCKETHANDLER_H
