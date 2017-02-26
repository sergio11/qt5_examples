import QtQuick 2.7
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.0

Item {
    id: root

    property alias cancel: cancel
    property alias save: save
    property alias empName: empName.text
    property alias empLastname: empLastname.text
    property alias empSalary: empSalaryTextField.text

    RowLayout {
        id: rowLayout
        x: 128
        y: 77
        width: 362
        height: 57
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: empNameLabel
            width: 120
            text: qsTr("Name")
            wrapMode: Text.WrapAnywhere
            Layout.columnSpan: 1
            Layout.rowSpan: 1
            font.bold: true
            font.pointSize: 13
            fontSizeMode: Text.VerticalFit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.preferredWidth: -1
            Layout.fillHeight: true
        }

        TextField {
            id: empName
            placeholderText: qsTr("Employee Name")
            Layout.fillWidth: true
            Layout.fillHeight: true
            renderType: Text.NativeRendering
        }
    }

    RowLayout {
        id: rowLayout1
        x: 139
        y: 161
        width: 362
        height: 55

        Label {
            id: empLastNameLabel
            text: qsTr("Lastname")
            font.bold: false
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        TextField {
            id: empLastname
            placeholderText: qsTr("the employee lastname")
            font.wordSpacing: -1
            font.weight: Font.Light
            font.capitalization: Font.Capitalize
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    RowLayout {
        id: rowLayout3
        x: 139
        y: 241
        width: 362
        height: 59

        Label {
            id: empSalaryLabel
            text: qsTr("Salary")
            Layout.fillHeight: true
            Layout.fillWidth: true
            font.bold: true
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        TextField {
            id: empSalaryTextField
            placeholderText: qsTr("The employee salary")
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }

    RowLayout {
        id: rowLayout2
        x: 283
        y: 329
        Layout.alignment: Qt.AlignTop | Qt.AlignRight
        width: 218
        height: 71

        Button {
            id: cancel
            text: qsTr("Button")
        }

        Button {
            id: save
            text: qsTr("Save")
        }
    }

}
