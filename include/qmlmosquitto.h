#ifndef QMLMOSQUITTO_H
#define QMLMOSQUITTO_H

#include <QQuickItem>
#include <mosquittoprivate.h>

class QMLMosquitto : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(QMLMosquitto)
    Q_PROPERTY(QString brokerAddress READ brokerAddress WRITE setBrokerAddress)
public:
    QMLMosquitto(QQuickItem *parent = nullptr);
    ~QMLMosquitto();
    QString brokerAddress();
    void setBrokerAddress(QString addr);
    void componentComplete();
private:
    bool _component_complete;
    QString _broker;
    MosquittoPrivate *_mp;
};

#endif // QMLMOSQUITTO_H
