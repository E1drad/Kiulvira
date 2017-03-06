import QtQuick 2.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Kiulvira")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
