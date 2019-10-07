import QtQuick 2.0
import QtQuick.Controls 2.4
import com.sequeira.mosquitto 1.0


Item {
    id: panel;
    property string broker: ""
    property string topic: ""

    QMLMosquitto{
        id: qmlMosquitto
        onMessageReceived:{
            textArea.append(topic + "(" + payload + ")")
            textArea.cursorPosition = textArea.text.length;
        }

        Component.onCompleted: {
            console.log("index.qml::QMLMosquitto::Component.onCompleted")
        }
    }

    Column{
        width: parent.width
        height: parent.height;
        spacing: 15;
        anchors.left: parent.left;
        anchors.leftMargin: 5;
        Row{
            spacing: 5;
            Label{
                text: "Broker:"
                anchors.verticalCenter: parent.verticalCenter;
            }
            TextField {
                id: broker;
                placeholderText: "Enter the broker address"
                text: panel.broker;
                enabled: !qmlMosquitto.isConnected;
            }
        }

        Row{
            spacing: 5;
            Label{
                text:  "Topic:"
                anchors.verticalCenter: parent.verticalCenter;
            }
            TextField {
                id: topic;
                placeholderText: "Enter the topic"
                text: panel.topic;
            }
        }


        Flow{
            spacing: 15;
            width: parent.width;
            Button {
                text: "Connect"
                enabled: !qmlMosquitto.isConnected
                onClicked: {
                    qmlMosquitto.brokerAddress = broker.text
                    qmlMosquitto.topic = topic.text;
                    qmlMosquitto.connect();
                }
            }
            Button {
                text: "Disconnect"
                enabled: qmlMosquitto.isConnected;
                onClicked: {
                    qmlMosquitto.disconnect();
                }
            }
            Button{
                text:  "Sub"
                enabled: qmlMosquitto.isConnected;
                onClicked: qmlMosquitto.subscribe()
            }
            Button {
                text: "Un-Sub"
                enabled: qmlMosquitto.isConnected;
                onClicked: qmlMosquitto.unSubscribe()
            }
            Button {
                text: "Clear"
                enabled: qmlMosquitto.isConnected;
                onClicked: textArea.text = "";
            }
        }

        ScrollView{
            id: scrollView;
            height: 150
            width: parent.width
            TextArea{
                id: textArea
                placeholderText: "Sub messages will appear here"
                cursorPosition: textArea.text.length
                background: Rectangle{
                    color: "transparent"
                    border.width: 2;
                }
            }
        }


        Label{
            text: "Publish:"
        }

        Row{
            spacing: 10
            TextField{
                placeholderText: "Text to Publish"
                enabled: qmlMosquitto.isConnected;
            }
            Button{
                text: "Pub"
                enabled: qmlMosquitto.isConnected;
            }
        }

    }

}
