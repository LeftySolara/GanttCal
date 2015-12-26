/******************************************************************************
 * employees.cpp : unit tests for Employee class
 * ****************************************************************************
 * Copyright (C) 2015 Jalen Adams
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

#include "employeetablemodel.h"

EmployeeTableModel::EmployeeTableModel(QObject *parent, QSqlDatabase database)
{
    db = QSqlDatabase::database("main");
    setTable("employee");
}

EmployeeTableModel::~EmployeeTableModel()
{
    db.close();
}

QModelIndex EmployeeTableModel::index(int row, int column, const QModelIndex &parent) const
{
    QModelIndex idx = createIndex(row, column);
    return idx;
}

int EmployeeTableModel::rowCount(const QModelIndex &parent) const
{
    QSqlQuery qry("SELECT COUNT(*) FROM employee");
    qry.next();
    return qry.numRowsAffected();
}

QSqlDatabase EmployeeTableModel::database() const
{
   return db;
}
