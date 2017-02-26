import QtQuick 2.7
import QtQuick.Controls 1.4


TableView {

    TableViewColumn {
        role: "id"
        title: qsTr("ID")
        width: 100
    }

    TableViewColumn {
        role: "firstname"
        title: qsTr("FirstName")
        width: 200
    }

    TableViewColumn {
        role: "lastname"
        title: qsTr("Lastname")
        width: 200
    }

    TableViewColumn {
        role: "salary"
        title: qsTr("Salary")
        width: 100
    }

    model: employeesModel
}



