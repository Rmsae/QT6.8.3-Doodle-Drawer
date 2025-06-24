import QtQuick 2.15
import QtQuick.Controls

Button {
    id: gameButton
    property color buttonColor: "#FFBA49"
    property color buttonPressedColor: "#BF8C39"
    property string buttonText: ""
    property int buttonTextPixelSize: 72

    text: gameButton.buttonText
    font.pixelSize: buttonTextPixelSize
    hoverEnabled: false

    background: Rectangle {
        radius: 5
        color: gameButton.down ? gameButton.buttonPressedColor : gameButton.buttonColor
    }

    contentItem: Text {
        text: gameButton.text
        color: "white"
        font.pixelSize: gameButton.buttonTextPixelSize
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    signal buttonClicked
    onClicked: buttonClicked()
} /* Die Verwendung eines Rectangle mit MouseArea ist ein älterer Ansatz,*/// Rectangle {
//     id: gameButton
//     property string buttonColor: "#FFBA49"
//     property string buttonPressedColor: "#bf8c39"
//     property string buttonText: ""
//     property int buttonTextPixelSize: 72

//     signal buttonClicked

//     radius: 5
//     color: buttonColor
//     Text {
//         anchors.centerIn: parent
//         color: "white"
//         text: gameButton.buttonText
//         font.pixelSize: gameButton.buttonTextPixelSize
//     }

//     MouseArea {
//         anchors.fill: parent
//         onPressed: gameButton.color = gameButton.buttonPressedColor
//         onReleased: gameButton.color = gameButton.buttonColor
//         onClicked: gameButton.buttonClicked()
//     }
// }

