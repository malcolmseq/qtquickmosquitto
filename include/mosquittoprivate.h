#ifndef MOSQUITTOPRIVATE_H
#define MOSQUITTOPRIVATE_H

#include<mosquittopp.h>

class MosquittoPrivate: public mosqpp::mosquittopp
{
public:
    MosquittoPrivate(const char *id, const char *topic, const char *host, int port);
    ~MosquittoPrivate();
    void on_connect(int rc);
    void on_disconnect(int rc);
    void on_error();
    void on_message(const struct mosquitto_message *);
    void on_publish(int);
    void on_unsubscribe(int);
    void on_subscribe(int, int, const int *);
    void on_log(int, const char *);

private:
    const char *_id;
    const char *_topic;
    const char *_host;
    int _port;
    int keepalive;
};

#endif // MOSQUITTOPRIVATE_H
