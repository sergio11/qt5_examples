#include "employeessqlmodel.h"
#include <QSqlRecord>
#include <QSqlField>
#include <QString>
#include <QSqlQuery>

EmployeesSQLModel::EmployeesSQLModel(QObject *parent, const QSqlDatabase &db) : QSqlTableModel(parent, db)
{
    QSqlQuery query(db);
    QString createTable;
    createTable.append("create table employees "
                       "(id integer primary key AUTOINCREMENT, "
                       "firstname varchar(30), "
                       "lastname varchar(30), "
                       "salary varchar(30))");
    if(query.exec(createTable)){
        qDebug() << "Employees Table Created";
    } else {
        qDebug() << "Failed create employees table";
        qDebug() << query.lastError().text();
    }
}


void EmployeesSQLModel::setQuery(const QSqlQuery &query)
{
    QSqlQueryModel::setQuery(query);
    generateRoleNames();
}

void EmployeesSQLModel::generateRoleNames()
{
    m_roleNames.clear();
    for( int i = 0; i < record().count(); i ++) {
        QString field = record().fieldName(i);
        qDebug() << "Field Name -> " << field;
        m_roleNames.insert(Qt::UserRole + i + 1, field.toUtf8());
    }
}

QVariant EmployeesSQLModel::data(const QModelIndex &index, int role) const
{
    QVariant value;

    if(role < Qt::UserRole) {
        value = QSqlQueryModel::data(index, role);
    }
    else {
        int columnIdx = role - Qt::UserRole - 1;
        QModelIndex modelIndex = this->index(index.row(), columnIdx);
        value = QSqlQueryModel::data(modelIndex, Qt::DisplayRole);
    }
    return value;
}


bool EmployeesSQLModel::addEmployee(const QString &firstname, const QString &lastname, const QString &salary)
{
    qDebug() << " Name -> " << firstname << " Lastname -> " << lastname << " Salary -> " << salary;
    QSqlRecord rec;
    // Id field
    QSqlField idField("id", QVariant::Int);
    idField.setValue(1);
    rec.append(idField);
    // FirstName Field
    QSqlField firstNameField("firstname", QVariant::String);
    firstNameField.setValue(firstname);
    rec.append(firstNameField);
    // Lastname Field
    QSqlField lastNameField("lastname", QVariant::String);
    lastNameField.setValue(lastname);
    rec.append(lastNameField);
    // Salary Field
    QSqlField salaryField("salary", QVariant::String);
    salaryField.setValue(salary);
    rec.append(salaryField);
    bool inserted = false;
    // append record to last position
    if(this->insertRecord(-1, rec)) {
        if(this->submitAll()) {
            inserted = true;
            this->database().commit();
        } else {
            this->database().rollback();
            qInfo() << "database error: " << this->lastError().text();
        }
    } else {
        qInfo() << "database error: " << this->lastError().text();
    }
    return inserted;
}
