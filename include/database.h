#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlQuery>
#include <QFileInfo>

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
};

#endif // DATABASE

