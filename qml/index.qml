import QtQuick 2.0

Rectangle {
    id: root;
    width: 800;
    height: 480;

    Row{
        spacing: 5
        Panel{
            id: panel1
            width: 350
            height: 480
            broker: "test.mosquitto.org"
            topic: "test"
        }
//        Panel{
//            id: panel2
//            width: 350
//            height: 480
//        }
    }
}
