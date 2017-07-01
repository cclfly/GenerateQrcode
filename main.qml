import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import cclfly.qt.QrImg 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "#66ccff"

//    Label {
//        text: qsTr("Second page")
//        anchors.centerIn: parent
//    }
    Rectangle {
        id: rectIn
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        color: "#FFFFFF"
        width: parent.width
        height: 48

        TextEdit {
            id: strIn
            text: qsTr("a")
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
            onTextChanged: {
                //strOut.text = text
                qrimg.setQrstr(text)
            }
        }
    }

    Rectangle {
        anchors.top: rectIn.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: "#125689"
        width: parent.width

        QrImg {
            id: qrimg
            anchors.centerIn: parent
            width: parent.width>parent.height?parent.height:parent.width
            height: parent.width>parent.height?parent.height:parent.width
        }
    }
/*
    Rectangle {
        id: rectOut
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        color: "#FFFFFF"
        width: parent.width
        height: 48

        TextInput {
            id: strOut
            text: qsTr("a")
            anchors.centerIn: parent
            horizontalAlignment: TextInput.AlignHCenter
        }
    }
*/
}
