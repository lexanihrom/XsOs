import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import GameComponents 1.0
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.1

ApplicationWindow {
    visible: true
    width: 500
    height: 500
    title: "Антиплагиат"
    FileDialog {
            id: fileDialog
            title: "Please choose a file"
            nameFilters: ["Text files (*.txt)", "HTML files (*.html, *.htm)"]
            onAccepted: {
                if (text2.activeFocus)
                    text2.text = shingles.readFile(fileUrl)
                if (text1.activeFocus)
                    text1.text = shingles.readFile(fileUrl)
            }
        }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Open")
                shortcut: StandardKey.Open
                onTriggered: {
                    fileDialog.selectExisting = true
                    fileDialog.open()
                }
            }
            MenuItem {
                text: qsTr("Copy")
                shortcut: StandardKey.Copy
                onTriggered: text2.copy();
            }
            MenuItem {
                text: qsTr("Paste")
                shortcut: StandardKey.Paste
                onTriggered: text1.paste();
            }

            MenuItem {
                text: qsTr("Exit")
                shortcut: StandardKey.Close
                onTriggered: Qt.quit();
            }

        }
    }


    Shingles {
    id: shingles
    }

    function niceText(text1, text2){
        return shingles.check(shingles.getshingles(shingles.cannonize(text1)),shingles.getshingles(shingles.cannonize(text2)))
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
            label1.text = niceText(text1.text, text2.text)
        }

    }

    Label {
        text: ""
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

