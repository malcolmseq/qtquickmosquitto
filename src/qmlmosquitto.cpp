#include "qmlmosquitto.h"

QMLMosquitto::QMLMosquitto(QQuickItem *parent):
    QQuickItem(parent),
    mosqpp::mosquittopp(QUuid::createUuid().toString(QUuid::WithoutBraces).toLatin1().data()),
    _component_complete(false), _is_connected(false), _is_subscribed(false), _port(1883), _keepalive(60)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
    qDebug()<<"QMLMosquitto::QMLMosquitto";
    mosqpp::lib_init();
}

QMLMosquitto::~QMLMosquitto()
{
    mosqpp::lib_cleanup();
}

QString QMLMosquitto::brokerAddress()
{
    return _broker;
}

void QMLMosquitto::setBrokerAddress(QString addr)
{
    if(_component_complete){
        qDebug()<<"QMLMosquitto::setBrokerAddress::Cannot set the broker address";
    } else {
        qDebug()<<"QMLMosquitto::setBrokerAddress::addr="<<addr;
        _broker = addr;
    }
}

QString QMLMosquitto::topic()
{
    return _topic;
}

void QMLMosquitto::setTopic(QString topic)
{
    if(_component_complete){
        qDebug()<<"QMLMosquitto::setTopic::Cannot set the topic";
    } else {
        qDebug()<<"QMLMosquitto::setTopic::topic="<<topic;
        _topic = topic;
    }
}

int QMLMosquitto::port()
{
    return _port;
}

void QMLMosquitto::setPort(int p)
{
    qDebug()<<"QMLMosquitto::setPort::port="<<p;
    _port = p;
}

int QMLMosquitto::keepAlive()
{
    return _keepalive;
}

void QMLMosquitto::setKeepAlive(int k)
{
    qDebug()<<"QMLMosquitto::setKeepAlive::keepAlive="<<k;
    _keepalive = k;
}

void QMLMosquitto::componentComplete()
{
    qDebug()<<"QMLMosquitto::componentComplete";
    _component_complete = false;
}

void QMLMosquitto::on_connect(int rc)
{
    qDebug()<<"QMLMosquitto::on_connect::rc="<<rc;
    if(rc == 0){
        _is_connected = true;
    } else {
        _is_connected = false;
    }
    emit isConnectedChanged(_is_connected);
}

void QMLMosquitto::on_disconnect(int rc)
{
    qDebug()<<"QMLMosquitto::on_disconnect::rc="<<rc;
    if(rc == 0){
        _is_connected = false;
        mosqpp::mosquittopp::loop_stop();
    } else {
        _is_connected = true;
    }
    emit isConnectedChanged(_is_connected);
}

void QMLMosquitto::on_error()
{
    qDebug()<<"QMLMosquitto::on_error";
}

void QMLMosquitto::on_log(int i, const char * str)
{
    qDebug()<<"QMLMosquitto::on_log::"<<i<<"::"<<str;
}

void QMLMosquitto::on_subscribe(int mid, int qos_count, const int *granted_qos)
{
    qDebug()<<"QMLMosquitto::on_subscribe::mid="<<mid
           <<", qos_count="<<qos_count<<", granted_qos"<<granted_qos
          <<", isSubscribed="<<_is_subscribed;
    if(_is_subscribed == false){
        _is_subscribed = true;
        emit isSubscribedChanged(true);
    }
}

void QMLMosquitto::on_unsubscribe(int mid)
{
    qDebug()<<"QMLMosquitto::on_unsubscribe::mid="<<mid<<", isSubscribed="<<_is_subscribed;
    if(_is_subscribed == true){
        _is_subscribed = false;
        emit isSubscribedChanged(false);
    }
}

void QMLMosquitto::on_message(const mosquitto_message *message)
{
    const char *payload = static_cast<const char* const>(message->payload);
    qDebug()<<"QMLMosquitto::on_message::mid="<<message->mid
           <<", topic="<<message->topic<<", payload="<<payload
          <<", qos="<<message->qos<<", retain="<<message->retain;
    emit messageReceived(QString(message->topic), QString(payload));
}

void QMLMosquitto::on_publish(int mid)
{
    qDebug()<<"QMLMosquitto::on_publish::mid="<<mid;
}

bool QMLMosquitto::isConnected()
{
    return _is_connected;
}

bool QMLMosquitto::isSubscribed()
{
    return _is_subscribed;
}

void QMLMosquitto::connect()
{
    qDebug()<<"QMLMosquitto::connect::broker="<<_broker<<", port="<<_port;
    int ret = mosqpp::mosquittopp::connect_async(_broker.toUtf8().data(), _port, _keepalive, "192.168.0.118");
    qDebug()<<"QMLMosquitto::connect::ret="<<ret<<"::"<<mosqpp::strerror(ret);
    mosqpp::mosquittopp::loop_start();
}

void QMLMosquitto::disconnect()
{
    qDebug()<<"QMLMosquitto::disconnect";
    mosqpp::mosquittopp::disconnect();
}

void QMLMosquitto::subscribe()
{
    int ret = mosqpp::mosquittopp::subscribe(NULL, _topic.toLatin1().data());
    qDebug()<<"QMLMosquitto::subscribe::ret="<<ret;
}

void QMLMosquitto::unSubscribe()
{
    int ret = mosqpp::mosquittopp::unsubscribe(NULL, _topic.toLatin1().data());
    qDebug()<<"QMLMosquitto::unSubscribe::ret="<<ret;
}

void QMLMosquitto::publish(QString text)
{
    int ret = mosqpp::mosquittopp::publish(NULL, _topic.toLatin1().data(), text.length(), text.toLatin1().data(), 0, false);
    qDebug()<<"QMLMosquitto::publish::ret="<<ret;
}
