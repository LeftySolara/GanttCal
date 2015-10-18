#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QErrorMessage>

class Database
{
public:
    Database(QString filename);
    ~Database();
//  add_employee(int id, const char *first, const char *last, const char *color);
//  remove_employee(int id);
//  add_shift();
//  remove_shift();

private:
    QSqlDatabase db;
    QSqlQuery qry;
    QErrorMessage errmsg;
};

#endif // DATABASE

