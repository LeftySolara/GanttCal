#include "../include/database.h"
#include "../include/utility.h"
#include <QtDebug>
#include <QFile>

#define SQL_INIT_SCRIPT "../scripts/db_init.sql"

Database::Database(QString filename)
{
    // Check if database file exists. If not, create it.
    QFile dbfile;
    dbfile.setFileName(filename);
    if (!dbfile.exists()) {
        qDebug("Could not find database file. Attempting to create...");
        dbfile.open(QIODevice::ReadWrite);
        if (!dbfile.exists())
            errmsg.showMessage("Error creating database file");
        dbfile.close();
    }

    // Create the database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);
    db.open();
    qry = QSqlQuery(db);

    // Run SQL script to initialize database
    QFile scriptfile;
    scriptfile.setFileName(SQL_INIT_SCRIPT);
    if (!scriptfile.exists()) {
        errmsg.showMessage("Error initializing database: script not found");
        QCoreApplication::exit();
    }
    if (utility::read_sql(&scriptfile, &qry))
        qDebug() << "Database initialized successfully";
    else
        errmsg.showMessage("Failed to initialize database");
}

Database::~Database()
{
    db.close();
}
