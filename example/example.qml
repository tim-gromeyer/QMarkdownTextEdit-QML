import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material
import QMarkdownTextEdit


Window {
    width: 640
    height: 400
    visible: true
    title: qsTr("Example Project")

    QMarkdownTextEdit {
        id: rect
        // text: "<b>Hello</b> <i>World!</i>"
        font.family: "Helvetica"
        font.pointSize: 20
        // color: "blue"
        // focus: true
    }
}
