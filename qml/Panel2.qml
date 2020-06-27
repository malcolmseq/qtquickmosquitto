import QtQuick 2.0
import QtQuick.Mosquitto 1.0

Rectangle {
    color:"#DEDEDE"

    QMLMosquitto{
        id: qmlMosquitto2;
        brokerAddress: "localhost";
        topic: "tester/#"
    }

}
