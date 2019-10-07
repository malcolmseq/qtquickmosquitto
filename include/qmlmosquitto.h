#ifndef QMLMOSQUITTO_H
#define QMLMOSQUITTO_H

#include <QQuickItem>
#include <mosquittopp.h>

class QMLMosquitto : public QQuickItem, public mosqpp::mosquittopp
{
    Q_OBJECT
    Q_DISABLE_COPY(QMLMosquitto)
    Q_PROPERTY(QString brokerAddress READ brokerAddress WRITE setBrokerAddress NOTIFY brokerAddressChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(int keepAlive READ keepAlive WRITE setKeepAlive NOTIFY keepAliveChanged)
    Q_PROPERTY(QString topic READ topic WRITE setTopic NOTIFY topicChanged)
    Q_PROPERTY(bool isConnected READ isConnected NOTIFY isConnectedChanged)
public:
    QMLMosquitto(QQuickItem *parent = nullptr);
    ~QMLMosquitto();

    // QProperties
    QString brokerAddress();
    void setBrokerAddress(QString addr);
    QString topic();
    void setTopic(QString topic);
    int port();
    void setPort(int p);
    int keepAlive();
    void setKeepAlive(int k);
    bool isConnected();

    // Invokables
    Q_INVOKABLE void connect();
    Q_INVOKABLE void disconnect();
    Q_INVOKABLE void subscribe();
    Q_INVOKABLE void unSubscribe();

    void componentComplete();

    // Mosquitto Internals
    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_error();
    void on_log(int, const char *);
    void on_subscribe(int mid, int qos_count, const int *granted_qos);
    void on_unsubscribe(int mid);
    void on_message(const struct mosquitto_message *);

signals:
    void brokerAddressChanged(QString brokerAddress);
    void portChanged(int port);
    void keepAliveChanged(int keepAlive);
    void topicChanged(QString newTopic);
    void isConnectedChanged(bool isConnected);
    void messageReceived(QString topic, QString payload);
private:
    bool _component_complete;
    QString _broker;
    QString _topic;
    bool _is_connected;

    int _port;
    int _keepalive;
};

#endif // QMLMOSQUITTO_H
