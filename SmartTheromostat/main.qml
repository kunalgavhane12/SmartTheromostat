import QtQuick 2.12
import QtQuick.Window 2.12
import App 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Smart Theromostat")

    SystemController{
        id: systemController
    }

    Loader{
        id: mainLoader
        anchors.fill: parent
        source: "qrc:/UI/HomeScreen/HomeScreen.qml"
    }
}
