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
    SECTION( "a shift object with valid members is valid" )
    {
        Shift s = Shift(SUNDAY, QTime(14,0), QTime(17,0));
        REQUIRE( s.is_valid() == true );
    }
    SECTION( "an end time that is earlier than a start time is invalid" )
    {
        Shift s = Shift(SUNDAY, QTime(17,0), QTime(9,0));
        REQUIRE( s.is_valid() == false );
    }
    SECTION( "an end time equal to the start time is invalid" )
    {
        Shift s = Shift(WEDNESDAY, QTime(9,0), QTime(9,0));
        REQUIRE( s.is_valid() == false );
    }
}

TEST_CASE( "a shift's length can be measured in hours", "[shift,length]" )
{
    Shift morning = Shift(WEDNESDAY, QTime(7,0), QTime(12,0));
    REQUIRE( morning.is_valid() == true );
    REQUIRE( morning.length() == 5);

    Shift afternoon = Shift(THURSDAY, QTime(13,0), QTime(17,30));
    REQUIRE( afternoon.is_valid() == true);
    REQUIRE( afternoon.length() == 4.5);
}

TEST_CASE( "shift objects can be compared to each other", "[shift,comparison]" )
{
    SECTION( "shifts with the same day, start, and end are equal" )
    {
        Shift first = Shift(FRIDAY, QTime(8,0), QTime(14,0));
        Shift second = Shift(FRIDAY, QTime(8,0), QTime(14,0));

        REQUIRE( (first == second) == true );
        REQUIRE( (first != second) == false);
    }
    SECTION( "shifts on different days are not equal" )
    {
        Shift first = Shift(FRIDAY, QTime(8,0), QTime(14,0));
        Shift second= Shift(SATURDAY, QTime(8,0), QTime(14,0));

        REQUIRE( (first == second) == false);
        REQUIRE( (first != second) == true );
    }
    SECTION( "shifts with different start times are not equal" )
    {
        Shift first = Shift(SATURDAY, QTime(8,0), QTime(14,0));
        Shift second = Shift(SATURDAY, QTime(10,0), QTime(14,0));

        REQUIRE( (first == second) == false);
        REQUIRE( (first != second) == true );
    }
    SECTION( "shifts with different end times are not equal" )
    {
        Shift first = Shift(FRIDAY, QTime(8,0), QTime(12,0));
        Shift second = Shift(FRIDAY, QTime(8,0), QTime(14,0));

        REQUIRE( (first == second) == false);
        REQUIRE( (first != second) == true );
    }
}
