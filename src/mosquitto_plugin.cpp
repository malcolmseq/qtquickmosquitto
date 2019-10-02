#include "mosquitto_plugin.h"
#include "qmlmosquitto.h"

#include <qqml.h>

void MosquittoPlugin::registerTypes(const char *uri)
{
    // @uri com.sequeiram.qmlcomponents
    qmlRegisterType<QMLMosquitto>(uri, 1, 0, "QMLMosquitto");
}

