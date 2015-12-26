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

#include "catch.hpp"
#include "models/employeetablemodel.h"
#include "utility/utility.h"
#include <QSqlDatabase>

#define TEST_DB "testdb.sqlite"

TEST_CASE( "The model can be created" )
{
    utility::create_database(TEST_DB);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "main");
    db.setDatabaseName(TEST_DB);

    EmployeeTableModel model;
    REQUIRE( model.database().databaseName() == TEST_DB );
}

TEST_CASE( "The number of rows can be counted" )
{
    EmployeeTableModel model;
    REQUIRE( model.database().databaseName() == TEST_DB );
    REQUIRE( model.rowCount() == 0);
}

TEST_CASE( "The number of columns can be counted" )
{
    EmployeeTableModel model;
    REQUIRE( model.database().databaseName() == TEST_DB );
    REQUIRE( model.columnCount() == 6 );
}
