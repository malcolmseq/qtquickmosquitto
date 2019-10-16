import QtQuick 2.0
import com.sequeira.mosquitto 1.0

Rectangle {
    color:"#DEDEDE"

    QMLMosquitto{
        id: qmlMosquitto2;
        brokerAddress: "localhost";
        topic: "tester/#"
    }

}
