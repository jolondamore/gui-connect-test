import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

Item {
	signal rectClicked()

	width: 640
	height: 480

	Rectangle {
		id: rect
		width: 100
		height: 100
		color: "red"
		anchors.centerIn: parent
		Text {
			anchors.centerIn: parent
			text: gui.text
		}
	}

	MouseArea {
        anchors.fill: parent
        onClicked: parent.rectClicked()
    }
}
