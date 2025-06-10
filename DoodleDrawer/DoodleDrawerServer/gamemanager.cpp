#include "gamemanager.h"

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    m_socketHandler = new WebSocketHandler(this);
}

GameManager::~GameManager()
{
    m_socketHandler->deleteLater();
}
