#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlRelationalTableModel>
#include <QErrorMessage>

class Database
{
friend class MainWindow;

public:
    Database(QString filename);
    ~Database();
    void create_connection(QString filename);
    float version();
    int employee_count();
    int shift_count();
    int next_id();
    bool add_employee(QString first, QString last, QString color, unsigned int max_hours);
//    bool remove_employee(int id);
//  add_shift();
//  remove_shift();

private:
    QSqlDatabase db;
    QSqlQuery qry;
    QSqlRelationalTableModel *employee_model;
    QSqlRelationalTableModel *shift_model;
    QErrorMessage errmsg;
};

#endif // DATABASE

