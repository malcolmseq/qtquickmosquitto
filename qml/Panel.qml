import QtQuick 2.0
import QtQuick.Controls 2.0


Item {
    Column{
        width: parent.width
        height: parent.height;
        spacing: 15;
        anchors.left: parent.left;
        anchors.leftMargin: 5;
        Label{
            text: "Broker:"
        }
        TextField {
            placeholderText: "Enter the broker address"
        }
        Label{
            text:  "Topic:"
        }
        TextField {
            placeholderText: "Enter the topic"
        }

        Flow{
            spacing: 15;
            width: parent.width;
            Button{
                text:  "Sub Start"
            }
            Button {
                text: "Sub Stop"
            }
            Button {
                text: "Clear"
            }
        }
        TextArea{
            placeholderText: "Sub messages"
            height: 150
            width: parent.width
            background: Rectangle{
                color: "transparent"
                border.width: 2;
            }
        }

        Label{
            text: "Publish:"
        }

        Row{
            spacing: 10
            TextField{
                placeholderText: "Text to Publish"
            }
            Button{
                text: "Pub"
            }
        }

    }

}
