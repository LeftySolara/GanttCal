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
#include "employee/employee.h"

TEST_CASE( "an employee can be initialized" )
{
  Employee mark = Employee(0, "Mark", "Johnson");
  Employee jan = Employee(1, "Jan", "Smith", "#282828");

  REQUIRE( mark.get_id() == 0);
  REQUIRE( mark.get_first_name() == "Mark" );
  REQUIRE( mark.get_last_name() == "Johnson" );
  REQUIRE( mark.get_display_color().name().toUpper() == "#6FCAE5");

  REQUIRE( jan.get_id() == 1);
  REQUIRE( jan.get_first_name() == "Jan" );
  REQUIRE( jan.get_last_name() == "Smith" );
  REQUIRE( jan.get_display_color().name().toUpper() == "#282828");
}
