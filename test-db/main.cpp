#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QQmlContext>
#include <QSqlQuery>
#include <employeessqlmodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sqlite.db");
    if (!db.open()) {
        qFatal("Cannot open database");
    }

    EmployeesSQLModel *employeesModel = new EmployeesSQLModel(0, db);
    QSqlQuery query("SELECT * FROM employees");
    employeesModel->setQuery(query);
    employeesModel->setSort(1, Qt::AscendingOrder);
    employeesModel->select();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("employeesModel", employeesModel);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}

