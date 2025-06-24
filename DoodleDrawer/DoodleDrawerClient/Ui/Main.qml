import QtQuick

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("DoodleDrawerClient")

    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "MainMenuScreen.qml"
    }
}
