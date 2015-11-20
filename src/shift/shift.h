/******************************************************************************
 * shift.h : struct for holding employee shift days and times
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

#ifndef SHIFT_H
#define SHIFT_H

#include <QTime>
#include <iostream>

enum Days {SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};

struct Shift
{
  Days day;
  QTime start_time;
  QTime end_time;

  Shift(Days weekday=SUNDAY, QTime start=QTime(9,0), QTime end=QTime(17,0));
  bool is_valid();
  float length();
};

 std::ostream& operator << (std::ostream& os, const Shift& rhs);
 bool operator == (const Shift& lhs, const Shift& rhs);
 bool operator != (const Shift& lhs, const Shift& rhs);

#endif // SHIFT_H

