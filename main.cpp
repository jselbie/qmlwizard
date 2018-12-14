#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <vector>
#include "mymodels.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Page1Model model1;
    Page2Model model2;
    Page3Model model3;
    NavigatorModel navigator;

    ModelViewPair mvp1 = {&model1, "qrc:/page1.qml"};
    ModelViewPair mvp2 = {&model2, "qrc:/page2.qml"};
    ModelViewPair mvp3 = {&model3, "qrc:/page3.qml"};

    QGuiApplication app(argc, argv);

    QQuickView view;

    view.setSource(QStringLiteral("qrc:/main.qml"));
    view.setWidth(640);
    view.setHeight(480);

    navigator._pages.push_back(mvp1);
    navigator._pages.push_back(mvp2);
    navigator._pages.push_back(mvp3);

    view.rootContext()->setContextProperty("navigator", &navigator);
    view.rootContext()->setContextProperty("model", mvp1._model);
    navigator._view = &view;
    view.show();


    return app.exec();
}


