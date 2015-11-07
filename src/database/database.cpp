#include "database.h"
#include "utility/utility.h"
#include <QtDebug>
#include <QFile>

#define SQL_INIT_SCRIPT "../scripts/db_init.sql"

Database::Database(QString filename)
{
    // TODO:
    // At startup, the program should attempt to create a directory to hold the
    // database if it doesn't exist. This should be implemented somewhere in
    // the main event loop, but it'll be done here until I make time to deal
    // with it.

    QFile dbfile;
    dbfile.setFileName(filename);

    // If the database doesn't exist, attempt to create it, then create a connection.
    // Assumes the database is formatted correctly if it already exists.
    if (!dbfile.exists()) {
        qDebug("Could not find database file. Attempting to create it...");
        dbfile.open(QIODevice::ReadWrite);
        if (!dbfile.exists())
            errmsg.showMessage("Error creating database file");
        dbfile.close();
        create_connection(filename);

        // execute sql script to initialize database
        QFile scriptfile;
        scriptfile.setFileName(SQL_INIT_SCRIPT);
        if (!scriptfile.exists()) {
            errmsg.showMessage("Error creating database: Initialization script not found");
            QCoreApplication::exit();
        }
        if (utility::read_sql(&scriptfile, &qry))
            qDebug() << "Database initialized successfully";
        else
            errmsg.showMessage("Failed to initialize database: Error executing script");
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

float Database::version()
{
    qry.exec("SELECT version FROM meta");
    qry.next();
    return qry.value("version").toFloat();
}

int Database::employee_count()
{
    qry.exec("SELECT employee_count FROM meta");
    qry.next();
    return qry.value("employee_count").toInt();
}

int Database::shift_count()
{
    qry.exec("SELECT shift_count FROM meta");
    qry.next();
    return qry.value("shift_count").toInt();
}

int Database::next_id()
{
    qry.exec("SELECT next_id FROM meta");
    qry.next();
    return qry.value("next_id").toInt();
}

bool Database::add_employee(QString first, QString last, QString color, unsigned int max_hours)
{
    int id = next_id();
    QString statement = "INSERT INTO employee (id_employee, last_name, first_name, max_hours, displayed, display_color) "
                        "VALUES (:id_employee, :last_name, :first_name, :max_hours, :displayed, :display_color)";

    if (!qry.prepare(statement)) {
        qDebug() << qry.lastError().text();
        return false;
    }
    qry.bindValue(":id_employee", id);
    qry.bindValue(":last_name", last);
    qry.bindValue(":first_name", first);
    qry.bindValue(":max_hours", max_hours);
    qry.bindValue(":displayed", 1);         // employee is displayed by default
    qry.bindValue(":display_color", color);
    if (!qry.exec()) {
        qDebug() << qry.lastError().text();
        return false;
    }

    // update next_id in meta table
    if (!qry.prepare("UPDATE meta SET next_id = :next_id"))
        return false;
    qry.bindValue(":next_id", ++id);
    qry.exec();

    // update employee_count in meta table
    int count = employee_count();
    if (!qry.prepare("UPDATE meta SET employee_count = :count"))
        return false;
    qry.bindValue(":count", ++count);
    qry.exec();

    return true;
}
