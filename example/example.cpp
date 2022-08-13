#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml/qqmlextensionplugin.h>

Q_IMPORT_QML_PLUGIN(QMarkdownTextEditPlugin)

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // The first subfolder is the libraryName followed by the regular
    // folder structure: LibraryName/Subfolder
    const QUrl url(u"qrc:/ExampleProjectApp/example/example.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
