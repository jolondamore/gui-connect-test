#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

#include "GuiManager.hpp"
#include "SampleWindow.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    /* Initialise GUI contexts */
    SampleWindow *mainGui = new SampleWindow(0);
    mainGui->setText("Hello, World!");
    SampleWindow *secondGui = new SampleWindow(1);
    secondGui->setText("Goodbye, World!");

    /* Initialise GUI manager and register GUI contexts */
    GuiManager *guiManager = new GuiManager(&engine, mainGui);
    guiManager->registerContext(secondGui);

    /* Start application */
    const QUrl url(u"qrc:/gui-connect-test/Main.qml"_qs);
    QObject::connect( &engine, &QQmlApplicationEngine::objectCreationFailed,
            &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
