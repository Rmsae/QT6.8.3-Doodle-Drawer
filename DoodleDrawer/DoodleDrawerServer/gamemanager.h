#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include "messageprocessorhandler.h"
#include "websockethandler.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    ~GameManager();

signals:

private:
    WebSocketHandler *m_socketHandler;
    MessageProcessorHandler *m_messageProcessHandler;
};

#endif // GAMEMANAGER_H
