#ifndef WEBSOCKETHANDLER_H
#define WEBSOCKETHANDLER_H

#include <QObject>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QtWebSockets>

class WebSocketHandler : public QObject
{
    Q_OBJECT
public:
    explicit WebSocketHandler(QObject *parent = nullptr);
    ~WebSocketHandler();

signals:
    void newMessageToProcess(QString message);

public slots:
    void onNewSocketConnection(void);
    void onTextMessageReceived(QString message);
    void onSocketDisconnected(void);

private:
    QWebSocketServer *m_socketServer;
    // QList<QWebSocket *> m_clientList;

    QMap<QString, QWebSocket *> m_clientList;
};

#endif // WEBSOCKETHANDLER_H
