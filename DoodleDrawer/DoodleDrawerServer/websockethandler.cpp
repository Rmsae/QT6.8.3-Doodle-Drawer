#include "websockethandler.h"
#include <QDebug>
#include <random>

WebSocketHandler::WebSocketHandler(QObject *parent)
    : QObject{parent}
{
    m_socketServer = new QWebSocketServer(QStringLiteral("DoodleDrawerServer"),
                                          QWebSocketServer::NonSecureMode,
                                          this);

    connect(m_socketServer,
            &QWebSocketServer::newConnection,
            this,
            &WebSocketHandler::onNewSocketConnection);

    if (m_socketServer->listen(QHostAddress::Any, 8585)) {
        qDebug() << QStringLiteral("Server is running");
    } else {
        qDebug() << QStringLiteral("Server unable to start listening for connections!");
    }
}

WebSocketHandler::~WebSocketHandler()
{
    m_socketServer->deleteLater();
}

void WebSocketHandler::onNewSocketConnection()
{
    qDebug() << QStringLiteral("New client connected!");

    std::random_device rd;
    std::default_random_engine generator;
    generator.seed(rd());

    std::uniform_int_distribution<int> idGenerator(10000, 9999);
    QString newClientID = QString::number(idGenerator(generator));

    while (m_clientList.keys().contains(newClientID)) {
        newClientID = QString::number(idGenerator(generator));
    }

    auto nextClient = m_socketServer->nextPendingConnection();
    nextClient->setParent(this);

    connect(nextClient,
            &QWebSocket::textMessageReceived,
            this,
            &WebSocketHandler::onTextMessageReceived);

    connect(nextClient, &QWebSocket::disconnected, this, &WebSocketHandler::onSocketDisconnected);

    //m_clientList.append(nextClient);
    nextClient->sendTextMessage("type:uniqueID;payLoad:" + newClientID);
    m_clientList[newClientID] = nextClient;
}

void WebSocketHandler::onTextMessageReceived(QString message)
{
    qDebug() << QStringLiteral("Server received: ") << message;
    emit newMessageToProcess(message);
}

void WebSocketHandler::onSocketDisconnected()
{
    auto client = qobject_cast<QWebSocket *>(sender());
    if (client) {
        //m_clientList.removeAll(client);
        if (client) {
            for (QMap<QString, QWebSocket *>::iterator mapIterator = m_clientList.begin();
                 mapIterator != m_clientList.end();
                 mapIterator++) {
                if (mapIterator.value() == client) {
                    QString uid = mapIterator.key();
                    m_clientList.remove(uid);
                    client->deleteLater();
                }
            }
        }
    }
}
