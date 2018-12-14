#ifndef MYMODELS_H
#define MYMODELS_H

#include <QObject>
#include <QQuickView>
#include <QString>


class MyModels : public QObject
{
    Q_OBJECT
public:
    explicit MyModels(QObject *parent = nullptr);
signals:

public slots:
};


class Page1Model : public QObject
{
    Q_OBJECT
public:
    explicit Page1Model(QObject *parent = nullptr);

    Q_PROPERTY(QString primaryText READ primaryText NOTIFY primaryTextChanged)
    QString _primaryText;
    QString primaryText();

signals:

    void primaryTextChanged();
public slots:
};


class Page2Model : public QObject
{
    Q_OBJECT
public:
    explicit Page2Model(QObject *parent = nullptr);
    Q_PROPERTY(QString primaryText READ primaryText NOTIFY primaryTextChanged)
    QString _primaryText;
    QString primaryText();

signals:
    void primaryTextChanged();
public slots:
};


class Page3Model : public QObject
{
    Q_OBJECT
public:
    explicit Page3Model(QObject *parent = nullptr);
    Q_PROPERTY(QString primaryText READ primaryText NOTIFY primaryTextChanged)
    QString _primaryText;

    QString primaryText();

signals:
    void primaryTextChanged();
public slots:
};

struct ModelViewPair
{
    QObject* _model;
    QString _qml;
};


class NavigatorModel : public QObject
{
    Q_OBJECT
public:
    explicit NavigatorModel(QObject *parent = nullptr);

    std::vector<ModelViewPair> _pages;
    int _index;

    QQuickView* _view;

    Q_PROPERTY(QString sourceQml READ sourceQml NOTIFY sourceQmlChanged)

    QString sourceQml() const;

signals:
    void sourceQmlChanged();

public slots:
    void jumpToNextPage();
};






#endif // MYMODELS_H
