#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controllers/websockethandler.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qputenv("QT_QUICK_CONTROLS_STYLE", "Basic"); // Oder "Material", "Fusion"

    WebSocketHandler socketHandler;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("webSocketHandler", &socketHandler);
    engine.loadFromModule("DoodleDrawerClient", "Main");

    return app.exec();
}
