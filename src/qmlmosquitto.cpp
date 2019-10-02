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
    Q_UNUSED(addr)
    if(_component_complete){
        qDebug()<<"QMLMosquitto::setBrokerAddress::Cannot set the broker address dynamically";
    } else {
        qDebug()<<"QMLMosquitto::setBrokerAddress::addr="<<addr;
        _broker = addr;
    }
}

void QMLMosquitto::componentComplete()
{
    qDebug()<<"QMLMosquitto::componentComplete";
    _component_complete = true;
}
