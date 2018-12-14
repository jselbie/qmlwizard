import QtQuick 2.9
import QtQuick.Window 2.2

Rectangle {
    visible: true

    Text
    {
        text: model.primaryText
    }

    MouseArea
    {
        id: ma
        anchors.fill: parent
        onClicked: navigator.jumpToNextPage()
    }

    Text
    {
        anchors.centerIn: parent
        text: "(Page 1) Click anywhere in this space to advance"
    }
}
