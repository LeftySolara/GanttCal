/******************************************************************************
 * shifts.cpp : unit tests for Shift struct
 ******************************************************************************
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
 *****************************************************************************/

#include "catch.hpp"
#include "shift/shift.h"

TEST_CASE( "shifts can be checked for validity", "[shift,validate]" )
{
  Shift s;

  SECTION( "a shift object with valid members is valid" )
  {
    s.day = MONDAY;
    s.start_time = QTime(9,0);
    s.end_time = QTime(17,0);
    REQUIRE( s.is_valid() == true );
  }
  SECTION( "an end time that is earlier than a start time is invalid" )
  {
    s.day = TUESDAY;
    s.start_time = QTime(17,0);
    s.end_time = QTime(9,0);
    REQUIRE( s.is_valid() == false );
  }
}

TEST_CASE( "a shift's length can be measured in hours", "[shift,length]" )
{
    Shift morning;
    Shift afternoon;

    morning.day = WEDNESDAY;
    morning.start_time = QTime(7,0);
    morning.end_time = QTime(12,0);

    afternoon.day = THURSDAY;
    afternoon.start_time = QTime(13,0);
    afternoon.end_time = QTime(17,30);

    REQUIRE( morning.is_valid() == true );
    REQUIRE( morning.length() == 5);

    REQUIRE( afternoon.is_valid() == true);
    REQUIRE( afternoon.length() == 4.5);
}
