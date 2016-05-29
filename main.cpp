#include <Shingles.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQmlContext>
#include <string>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Shingles>("GameComponents", 1, 0, "Shingles");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/window.qml")));

    return app.exec();
}

