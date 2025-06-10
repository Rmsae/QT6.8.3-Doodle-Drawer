#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
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
};

#endif // GAMEMANAGER_H
