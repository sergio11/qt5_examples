import QtQuick 2.0
import QtQuick.Dialogs 1.2

EmployeeForm {
    id: form
    save.onClicked: function () {
        console.log("Save the employee " + empName);
        var result = employeesModel.addEmployee(empName, empLastname, empSalary);
        if(result){
            console.log("Employee " + empName + " saved");
            empSavedDialog.open();
            employeesModel.select();
        } else {
            console.log("Failed to saved " + empName);
            errorSaveEmpDialog.open();
        }
    }

    MessageDialog {
        id: empSavedDialog
        icon: StandardIcon.Information
        standardButtons: StandardButton.Close
        title: "Employee saved"
        text: "The employee was saved successfully"
    }

    MessageDialog {
        id: errorSaveEmpDialog
        icon: StandardIcon.Critical
        standardButtons: StandardButton.Close
        title: "Operation Failed"
        text: "Failed to save employee"
    }

}
