#ifndef EMPLOYEESSQLMODEL_H
#define EMPLOYEESSQLMODEL_H

#pragma once
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>


class EmployeesSQLModel : public QSqlTableModel
{
    Q_OBJECT

    public:
        explicit EmployeesSQLModel(QObject *parent = 0, const QSqlDatabase &db = QSqlDatabase());
        Q_INVOKABLE bool addEmployee(const QString &name, const QString &lastname, const QString &salary);
        void setQuery(const QSqlQuery &query);
        QVariant data(const QModelIndex &index, int role) const;
        QHash<int, QByteArray> roleNames() const {	return m_roleNames;	}

    private:
        void generateRoleNames();
        QHash<int, QByteArray> m_roleNames;
};

#endif // EMPLOYEESSQLMODEL_H
