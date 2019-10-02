#ifndef QMLMOSQUITTO_H
#define QMLMOSQUITTO_H

#include <QQuickItem>

class QMLMosquitto : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QMLMosquitto)
    Q_PROPERTY(QString brokerAddress READ brokerAddress)
public:
    QMLMosquitto(QQuickItem *parent = nullptr);
    ~QMLMosquitto();
    QString brokerAddress();
};

#endif // QMLMOSQUITTO_H
