#include "../include/database.h"
#include <QtDebug>

Database::Database(QString filename)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);

    if (!db.open())
        qDebug("Failed to open database");
    else
        qDebug("Database opened successfully");
}

Database::~Database()
{
    db.close();
}
