#include "include/mosquittoprivate.h"

MosquittoPrivate::MosquittoPrivate(const char *id, const char *topic, const char *host, int port)
    :mosqpp::mosquittopp(id), _id(id), _topic(topic), _host(host), _port(port), keepalive(60)
{
    mosqpp::lib_init();
    connect_async(_host, _port, keepalive);
    loop_start();
}

MosquittoPrivate::~MosquittoPrivate()
{
    loop_stop();
    mosqpp::lib_cleanup();
}

void MosquittoPrivate::on_connect(int rc)
{

}

void MosquittoPrivate::on_disconnect(int rc)
{

}

void MosquittoPrivate::on_error()
{

}

void MosquittoPrivate::on_message(const mosquitto_message *)
{

}

void MosquittoPrivate::on_publish(int)
{

}

void MosquittoPrivate::on_unsubscribe(int)
{

}

void MosquittoPrivate::on_subscribe(int, int, const int *)
{

}

void MosquittoPrivate::on_log(int, const char *)
{

}
