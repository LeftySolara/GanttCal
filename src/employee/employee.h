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

  void set_first_name(QString name);
  void set_last_name(QString name);
  void set_display_color(QColor color);
  void set_display_color(QString color);

  QString get_first_name();
  QString get_last_name();
  QColor get_display_color();
  int get_shift_count();
  double get_hours();
};

#endif // EMPLOYEE_H

