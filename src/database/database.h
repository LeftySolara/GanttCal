#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QErrorMessage>

class Database
{
public:
    Database(QString filename);
    ~Database();
    void create_connection(QString filename);
    float version();
    int employee_count();
    int shift_count();
    int next_id();
    bool add_employee(QString first, QString last, QString color, unsigned int max_hours);
//  remove_employee(int id);
//  add_shift();
//  remove_shift();

private:
    QSqlDatabase db;
    QSqlQuery qry;
    QErrorMessage errmsg;
};

#endif // DATABASE

