#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QErrorMessage>

class Database
{
public:
    Database(QString filename);
    ~Database();
    bool add_employee(int id, QString first, QString last, QString color, unsigned int max_hours);
//  remove_employee(int id);
//  add_shift();
//  remove_shift();

private:
    QSqlDatabase db;
    QSqlQuery qry;
    QErrorMessage errmsg;
};

#endif // DATABASE

