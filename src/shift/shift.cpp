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

#include "shift.h"
using std::ostream;

Shift::Shift(Days weekday, QTime start, QTime end)
{
    day = weekday;
    start_time = start;
    end_time = end;
}

// Checks that start and end times are valid time formats and
// that the start time is earlier than the end time
bool Shift::is_valid()
{
    return start_time.isValid()
        && end_time.isValid()
        && (start_time < end_time)
        && (SUNDAY <= day && day <= SATURDAY);
}

// returns the number of seconds from the start time to the end time
float Shift::length()
{
    return float(start_time.secsTo(end_time)) / 3600.00;  // convert to hours
}

ostream& operator << (ostream& os, const Shift& rhs)
{
    switch (rhs.day) {
    case SUNDAY:
        os << "Sunday";
        break;
    case MONDAY:
        os << "Monday";
        break;
    case TUESDAY:
        os << "Tuesday";
        break;
    case WEDNESDAY:
        os << "Wednesday";
        break;
    case THURSDAY:
        os << "Thursday";
        break;
    case FRIDAY:
        os << "Friday";
        break;
    case SATURDAY:
        os << "Saturday";
        break;
    default:
        os << "Unknown";
        break;
    }

    os << rhs.start_time.toString("hh:mm").constData()
       << rhs.end_time.toString("hh:mm").constData();
    return os;
}

bool operator == (const Shift& lhs, const Shift& rhs)
{
    return (lhs.day == rhs.day)
        && (lhs.start_time == rhs.start_time)
        && (lhs.end_time == rhs.end_time);
}

bool operator != (const Shift& lhs, const Shift& rhs)
{
    return (lhs.day != rhs.day)
        || (lhs.start_time != rhs.start_time)
        || (lhs.end_time != rhs.end_time);
}
