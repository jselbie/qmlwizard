#include "mymodels.h"
#include <QQuickView>
#include <QQuickItem>
#include <QQmlContext>

MyModels::MyModels(QObject *parent) : QObject(parent)
{

}


Page1Model::Page1Model(QObject *parent) : QObject(parent)
{
    _primaryText = "This is is the text for page 1";
}
QString Page1Model::primaryText()
{
    return _primaryText;
}

Page2Model::Page2Model(QObject *parent) : QObject(parent)
{
    _primaryText = "This is is the text for page 2";
}
QString Page2Model::primaryText()
{
    return _primaryText;
}


Page3Model::Page3Model(QObject *parent) : QObject(parent)
{
    _primaryText = "This is is the text for page 3";
}

QString Page3Model::primaryText()
{
    return _primaryText;
}


NavigatorModel::NavigatorModel(QObject *parent) : QObject(parent)
{
    _index = 0;
    _view = nullptr;
}

QString NavigatorModel::sourceQml() const
{
    return _pages[_index]._qml;
}


void NavigatorModel::jumpToNextPage()
{
    _index++;


    if (_pages.size() == 0)
    {
        return;
    }

    if (_index >= _pages.size())
    {
        _index = 0;
    }

    _view->rootContext()->setContextProperty("navigator", this);
    _view->rootContext()->setContextProperty("model", _pages[_index]._model);

    emit sourceQmlChanged();
}
