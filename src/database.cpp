#include "../include/database.h"
#include "../include/utility.h"
#include <QtDebug>
#include <QFile>

#define SQL_INIT_SCRIPT "../scripts/db_init.sql"

Database::Database(QString filename)
{
    QFile dbfile;
    dbfile.setFileName(filename);

    // if the database doesn't exist, attempt to create it
    if (!dbfile.exists()) {
        qDebug("Could not find database file. Attempting to create...");
        dbfile.open(QIODevice::ReadWrite);
        if (!dbfile.exists())
            errmsg.showMessage("Error creating database file");
        dbfile.close();

        // create connection to db so we can query it
        create_connection(filename);

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
    else
        create_connection(filename);
}

Database::~Database()
{
    db.close();
}

void Database::create_connection(QString filename)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);
    if (!db.open()) {
        qDebug() << "Error opening database file";
        QCoreApplication::exit();
    }
    qry = QSqlQuery(db);
}

bool Database::add_employee(int id, QString first, QString last, QString color, unsigned int max_hours)
{
    // execute query to add to Employee table in db
}
