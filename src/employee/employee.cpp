/******************************************************************************
 * employee.cpp : implementation file for Employee class
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

#include "employee.h"

Employee::Employee(int new_id, QString first, QString last, QString color) : id(new_id)
{
  first_name = first;
  last_name = last;
  display_color = QColor(color);
}

Employee::~Employee()
{
  for (unsigned int i = 0; i < schedule.size(); ++i)
    delete schedule[i];
  schedule.clear();
}

void Employee::add_shift(Days day, QTime start, QTime end)
{
  Shift *new_shift = new Shift;
  new_shift->day = day;
  new_shift->start_time = start;
  new_shift->end_time = end;
  schedule.push_back(new_shift);
}

void Employee::remove_shift(Days day, QTime start)
{
  auto it = schedule.begin();

  while (it != schedule.end()) {
    if ((*it)->day == day && (*it)->start_time == start) {
      delete *it;
      it = schedule.erase(it);
      break;
    }
    else {
      ++it;
    }
  }
}

// Checks for any invalids shifts in schedule
bool Employee::schedule_is_valid()
{
  for (Shift *s : schedule) {
    if (!s->is_valid()) {
      return false;
    }
  }
  return true;
}

void Employee::set_first_name(QString name)
{
  first_name = name;
}

void Employee::set_last_name(QString name)
{
  last_name = name;
}

void Employee::set_display_color(QColor color)
{
  display_color = color;
}

void Employee::set_display_color(QString color)
{
  display_color = QColor(color);
}

int Employee::get_id()
{
  return id;
}

QString Employee::get_first_name()
{
  return first_name;
}

QString Employee::get_last_name()
{
  return last_name;
}

QColor Employee::get_display_color()
{
  return display_color;
}

int Employee::get_shift_count()
{
  return schedule.size();
}

float Employee::get_hours()
{
  float hours = 0;
  for (Shift* shift : schedule)
    hours += shift->length();

  return hours;
}
