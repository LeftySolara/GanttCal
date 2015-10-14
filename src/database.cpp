#include "../include/database.h"
#include <QDebug>

Database::Database(QString filename)
{
    db.addDatabase("QSQLITE", "Connection");
    db.setDatabaseName(filename);

    if (!db.open())
        qDebug() << "Failed to open database";
    else
        qDebug() << "Database opened successfully";
}

Database::~Database()
{
    db.close();
}
