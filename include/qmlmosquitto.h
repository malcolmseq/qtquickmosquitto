#ifndef QMLMOSQUITTO_H
#define QMLMOSQUITTO_H

#include <QQuickItem>
#include <mosquittopp.h>

class QMLMosquitto : public QQuickItem, public mosqpp::mosquittopp
{
    Q_OBJECT
    Q_DISABLE_COPY(QMLMosquitto)
    Q_PROPERTY(QString brokerAddress READ brokerAddress WRITE setBrokerAddress)
    Q_PROPERTY(QString topic READ topic WRITE setTopic)
public:
    QMLMosquitto(QQuickItem *parent = nullptr);
    ~QMLMosquitto();
    QString brokerAddress();
    void setBrokerAddress(QString addr);
    QString topic();
    void setTopic(QString topic);
    void componentComplete();
private:
    bool _component_complete;
    QString _broker;
    QString _topic;
};

#endif // QMLMOSQUITTO_H
