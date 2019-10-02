import QtQuick 2.0
import com.sequeira.mosquitto 1.0

Rectangle {
    id: root;
    width: 800;
    height: 480;

    QMLMosquitto{
        id: qmlMosquitto
        brokerAddress: "test.mosquitto.org"
        Component.onCompleted: {
            console.log("index.qml::QMLMosquitto::Component.onCompleted")
        }
    }

}
