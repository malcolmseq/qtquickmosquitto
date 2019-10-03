#include "qmlmosquitto.h"

QMLMosquitto::QMLMosquitto(QQuickItem *parent):
    QQuickItem(parent),_component_complete(false)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

QMLMosquitto::~QMLMosquitto()
{
}

QString QMLMosquitto::brokerAddress()
{
    return _broker;
}

void QMLMosquitto::setBrokerAddress(QString addr)
{
    if(_component_complete){
        qDebug()<<"QMLMosquitto::setBrokerAddress::Cannot set the broker address dynamically";
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
        qDebug()<<"QMLMosquitto::setTopic::Cannot set the topic dynamically";
    } else {
        qDebug()<<"QMLMosquitto::setTopic::topic="<<topic;
        _topic = topic;
    }
}

void QMLMosquitto::componentComplete()
{
    qDebug()<<"QMLMosquitto::componentComplete";
    _component_complete = true;
}
