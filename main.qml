import QtQuick 2.3
import QtQuick.Window 2.2

import Pairs 1.0

Window {
    visible: true
    width: 800
    height: 600

    Field {
        id: field1
    }

    Rectangle {
        id: board
        color: "lightgray"
        anchors.fill: parent
        anchors.margins: 10
        property bool state: true

        Grid {
            id: grid
            rows: field1.width
            columns: field1.height
            spacing: 4

            Repeater {
                model: field1.width * field1.height

                Rectangle {
                    id: cellItem
                    width: 48
                    height: 48
                    property Cell cell: field1.cellAt(index % field1.width, index / field1.width)

                    Text {
                        text: switch(cell.mark) {
                              case 0:
                                  return ""
                              case 1:
                                  return "X"
                              case 2:
                                  return "0"
                              }
                        font.pixelSize: parent.height
                        anchors.centerIn: parent

                    }

                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton
                        onClicked:{
                            if (mouse.button==Qt.LeftButton) {
                                if (board.state){
                                    cell.openX()
                                    board.state = false
                                } else {
                                    cell.openO()
                                    board.state = true
                                }
                            }
                        }
                    }
                }
            }
        }
        Text {
            text: if (board.state){
                      return "Ход крестиков"
                  } else {
                    return "Ход ноликов"
                  }
            anchors.right: board.right
            font.pixelSize: 35
        }
    }
}
