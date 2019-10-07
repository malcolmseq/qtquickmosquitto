#ifndef MOSQUITTO_PLUGIN_H
#define MOSQUITTO_PLUGIN_H

#include <QQmlExtensionPlugin>
#include <QDebug>

class MosquittoPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MOSQUITTO_PLUGIN_H
