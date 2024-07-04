import QtQuick
import QtQuick.Controls.Material
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Gui Connect Test")

    StackView {
        id: stack
        initialItem: mainView
        anchors.fill: parent
    }

    Component {
        id: mainView
        Window0 {
            onRectClicked: {
                stack.push(secondView)
                gui.updateWindow(1)
            }
        }
    }

    Component {
        id: secondView
        Window1 {
            onRectClicked: {
                stack.pop()
                gui.updateWindow(0)
            }
        }
    }
}
