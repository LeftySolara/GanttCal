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

double Employee::get_hours()
{
  int secs = 0;
  for (Shift* shift : schedule)
    secs += shift->length();

  double hours = secs / 3600;
  return hours;
}
