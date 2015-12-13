/* Copyright (C) 2015 Jalen Adams
 *
 * Authors: Jalen Adams <leftysolara@gmail.com>
 *
 * This file is part of GanttCal.
 *
 * GanttCal is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GanttCal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GanttCal.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "database.h"
#include "utility/utility.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>

#define SQL_INIT_SCRIPT "../scripts/db_init.sql"

Database::Database(QString filename)
{
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
      qDebug() << "create_connection(): " << db.lastError();
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

bool Database::remove_employee(int id)
{
    QString statement = "DELETE FROM employee WHERE id_employee = :id";
    if (!qry.prepare(statement)) {
      qDebug() << qry.lastError().text();
      return false;
    }

    qry.bindValue(":id", id);
    if (!qry.exec()) {
      qDebug() << qry.lastError().text();
      return false;
    }
    return true;
}

QSqlDatabase Database::get_db()
{
    return db;
}
