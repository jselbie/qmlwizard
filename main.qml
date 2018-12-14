import QtQuick 2.9
import QtQuick.Window 2.2

Rectangle {
    visible: true
    anchors.fill: parent

    Text
    {
        id: txt
        text: "This is the main page"
    }

    Loader
    {
        id: loader
        anchors.fill: parent
        source: navigator.sourceQml
    }
}
