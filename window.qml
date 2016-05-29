import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import GameComponents 1.0
import QtQuick.Window 2.2

Window {
    visible: true
    width: 500
    height: 500


    Shingles {
    id: shingles
    }

    TextArea {
        id: text1
        width: parent.width / 2
        height: parent.height * 0.7
    }

    TextArea {
        id: text2
        width: parent.width / 2
        height: parent.height * 0.7
        anchors.left: text1.right
    }

    Button {
        id: button
        text: "check"
        anchors.top: text1.bottom
        anchors.right: text2.left
        onClicked: {
            //label1.text = shingles.check(shingles.getshingles(shingles.cannonize(text1.text)),shingles.getshingles(shingles.cannonize(text2.text)))
            console.log(shingles.check(shingles.getshingles(shingles.cannonize("alexey  &&1233 ddd?")),shingles.getshingles(shingles.cannonize("alexey"))));
        }

    }

    Label {
        text: shingles.cannonize("alexey")
        anchors.top: text1.bottom
        anchors.left: button.right
        font.pixelSize: 22
        font.italic: true
        id: label1
        visible: true
    }


    Label {
        text: "%"
        anchors.top: text1.bottom
        anchors.left: label1.right
        font.pixelSize: 22
        visible: if (label1.text.length != 0){
                     true
                 } else {
                     false
                 }
    }
}

