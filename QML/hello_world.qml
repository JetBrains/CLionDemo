import QtQuick
import QtQuick.Controls

Window {
    visible: true
    width: 400
    height: 300
    title: "Hello World"

    Button {
        text: "Hello World!"
        anchors.centerIn: parent
        width: 200
        height: 100
        onClicked: {
            console.log("Button clicked!")
        }
    }
}
