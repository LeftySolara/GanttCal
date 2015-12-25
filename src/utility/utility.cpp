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

#include "utility.h"
#include <QtDebug>
#include <QFileInfo>
#include <QSettings>
#include <QSqlDatabase>

#define DEFAULT_DATABASE "ganttcal.sqlite"
#define SQL_INIT_SCRIPT "../scripts//db_init.sql"

namespace utility
{

void apply_defaults()
{
    QSettings settings;

    // default database location
    QFileInfo settings_info(settings.fileName());
    QString to_replace = settings_info.fileName();
    QString db_filename = settings.fileName().replace(to_replace, DEFAULT_DATABASE);
    settings.setValue("database_path", db_filename);
}

bool settings_exist()
{
    QSettings settings;
    QFileInfo settings_info(settings.fileName());
    return settings_info.exists();
}

// reads and executes the given sql script
bool read_sql(QFile *script_file, QSqlQuery *qry)
{
    if (!script_file->open(QIODevice::ReadOnly)) {
        return false;
    }
    else
    {
        QTextStream in(script_file);
        QString statement = "";
            while (!in.atEnd())
            {
                QString line = in.readLine();
                // ignore comments
                if (line.startsWith("--") || line.length() == 0) {
                    continue;
                }
                statement += line;
                if (statement.endsWith(";")) {
                    // remove semicolon at end
                    statement.chop(1);
                    if (qry->prepare(statement)) {
                          qry->exec();
                          statement = "";
                    }
                    else
                      return false;
                }
            }
            script_file->close();
        }
        return true;
}

// create and initialize the database, assuming the file doesn't already exist
bool create_database(QString filename)
{
    // create the file
    QFile dbfile;
    dbfile.setFileName(filename);

    dbfile.open(QIODevice::ReadWrite);
    if (!dbfile.exists()) {
        qDebug() << "Unable to create the database.";
        return false;
    }
    dbfile.close();

    // make a database connection and set up the query
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(filename);
    if (!db.open()) {
        qDebug() << "Unable to open database.";
        return false;
    }
    QSqlQuery qry(db);

    // run script to set up the database
    QFile scriptfile;
    scriptfile.setFileName(SQL_INIT_SCRIPT);
    if (!scriptfile.exists()) {
        qDebug() << "Cannot find database initialization script.";
        return false;
    }
    if (!read_sql(&scriptfile, &qry)) {
        qDebug() << "Error executing initialization script.";
        return false;
    }
    qDebug() << "Database initialized successfully.";
    return true;
}

}
