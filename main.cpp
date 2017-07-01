#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qrencode.h>
#include "qrimg.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<QrImg>("cclfly.qt.QrImg",1,0,"QrImg");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
