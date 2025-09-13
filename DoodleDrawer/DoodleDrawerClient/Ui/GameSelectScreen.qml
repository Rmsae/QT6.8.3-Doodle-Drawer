import QtQuick 2.0

Item {
    id: gameSelectScreen

    Rectangle {
        id: background
        anchors.fill: parent
        color: "#23001E"
    }

    Text {
        id: titleText
        font.pixelSize: 72
        font.bold: true
        anchors {
            top: parent.top
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        color: "white"
        text: "DoodleDrawer"
    }

    GameButton {
        id: createGameButton
        anchors {
            top: titleText.bottom
            topMargin: 160
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Create Game"
        buttonTextPixelSize: 48
        width: 336
        height: 105

        onButtonClicked: webSocketHandler.connectToServer("ws://127.0.0.1:8585")
        //onButtonClicked: console.log("Button Create Game clicked!")
    }

    GameButton {
        id: joinGameButton
        anchors {
            top: createGameButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Join Game"
        buttonTextPixelSize: 48
        width: 336
        height: 105
        // onButtonClicked: mainLoader.source = "JoinLobbyScreen.qml"
        onButtonClicked: console.log("Button Join Game clicked!")
    }

    GameButton {
        id: backButton
        anchors {
            top: joinGameButton.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }

        buttonText: "Back"
        buttonTextPixelSize: 48
        width: 336
        height: 105
        onButtonClicked: mainLoader.source = "MainMenuScreen.qml"
    }
}
