#include "employeetablemodel.h"

EmployeeTableModel::EmployeeTableModel(QObject *parent, QSqlDatabase database)
{
    db = QSqlDatabase::database("main");
    qry = QSqlQuery(db);
    setTable("employee");
}

EmployeeTableModel::~EmployeeTableModel()
{
    db.close();
}
