/******************************************************************************
 * employee.h : class for managing Employee information
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

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define DEFAULT_COLOR "#6FCAE5"

#include <QColor>
#include <vector>
#include "shift/shift.h"

class Employee
{
private:
    const int id;
    QString first_name;
    QString last_name;
    QColor display_color;
    std::vector<Shift*> schedule;
public:
    Employee(int new_id, QString first, QString last, QString color=DEFAULT_COLOR);
    ~Employee();

    void add_shift(Days day, QTime start, QTime end);
    void remove_shift(Days day, QTime start);
    bool schedule_is_valid();

    void set_first_name(QString name);
    void set_last_name(QString name);
    void set_display_color(QColor color);
    void set_display_color(QString color);

    int get_id();
    QString get_first_name();
    QString get_last_name();
    QColor get_display_color();
    int get_shift_count();
    float get_hours();
};

#endif // EMPLOYEE_H

