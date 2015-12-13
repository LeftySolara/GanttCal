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

#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QErrorMessage>

class Database
{
friend class MainWindow;

public:
    Database() {;}
    Database(QString filename);
    ~Database();
    void create_connection(QString filename);
    float version();
    int employee_count();
    int shift_count();
    int next_id();
    bool add_employee(QString first, QString last, QString color, unsigned int max_hours);
    bool remove_employee(int id);
    QSqlDatabase get_db();
  //  add_shift();
  //  remove_shift();

private:
    QSqlDatabase db;
    QSqlQuery qry;
    QErrorMessage errmsg;
};

#endif // DATABASE

