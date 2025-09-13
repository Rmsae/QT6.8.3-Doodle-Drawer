#include "messageprocessorhandler.h"
#include <QDebug>

MessageProcessorHandler::MessageProcessorHandler(QObject *parent)
    : QObject{parent}
{}

void MessageProcessorHandler::processMessage(QString message)
{
    //qDebug() << QStringLiteral("Server App: Message to process: ") << message;

    //type:createGame;payLoad:0;
    //type:joinGame;payLoad:4000;sender:5555
    //type:message;payLoad:HelloWorld;sender:5555

    QStringList separated = message.split(";");

    if (separated.first() == "type:createGame") {
        //create game
        qDebug() << QStringLiteral("Create game request");

    } else if (separated.first() == "type:joinGame") {
        //join game
        qDebug() << QStringLiteral("join game request");

    } else if (separated.first() == "type:message") {
        // message to lobby
        qDebug() << QStringLiteral("message request");
    }
}
