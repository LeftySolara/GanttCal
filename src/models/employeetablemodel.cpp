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
#include <QSqlRecord>
#include <QSqlField>

EmployeeTableModel::EmployeeTableModel(QObject *parent, QSqlDatabase database)
{
    db = QSqlDatabase::database("main");
    setEditStrategy(EmployeeTableModel::OnManualSubmit);
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

// All indexes in the table are top-level and have no parents
// Therefore, function always returns an invaild index
QModelIndex EmployeeTableModel::parent(const QModelIndex &child) const
{
   QModelIndex idx;
   return idx;
}

int EmployeeTableModel::rowCount(const QModelIndex &parent) const
{
    QSqlQuery qry("SELECT COUNT(*) FROM employee");
    qry.next();
    return qry.numRowsAffected();
}

int EmployeeTableModel::columnCount(const QModelIndex &parent) const
{
    QSqlQuery qry("SELECT * FROM employee");
    qry.next();
    return qry.record().count();
}

QVariant EmployeeTableModel::data(const QModelIndex &idx, int role) const
{
    return idx.data(role);
}

bool EmployeeTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        QSqlQuery qry;
        QSqlField field = qry.record().field(index.column());

        qry.prepare("UPDATE employee SET ? = ? WHERE id_employee = ?");
        qry.bindValue(0, field.name());
        qry.bindValue(2, index.row());

        // The database table only contains ints and text
        if (value.canConvert(QMetaType::Bool))
            qry.bindValue(1, value.toBool());
        else if (value.canConvert(QMetaType::Int))
            qry.bindValue(1, value.toInt());
        else if (value.canConvert(QMetaType::QString))
            qry.bindValue(1, value.toString());
        //else
            // raise error and return false

        if (qry.exec()) {
            emit dataChanged(index, index);
            return true;
        }
    }
    return false;
}

bool EmployeeTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{

}

QSqlDatabase EmployeeTableModel::database() const
{
   return db;
}
