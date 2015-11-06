#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>
#include <time.h>

enum Days {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

struct Shift
{
  unsigned short day;
  time_t start_time;
  time_t end_time;
};

class Employee
{
private:
  int id_; // foreign key for shift table in database
  const char *display_color_;
  const char *first_name_;
  const char *last_name_;
  std::vector<Shift> shifts_;
public:
  Employee(int id, const char *first, const char *last, const char *color="#FFFFFF");
  ~Employee();
  void add_shift(Days day, time_t start, time_t end);
  void remove_shift(Days day, time_t start);
  double hours();
  int shift_count() { return shifts_.size(); }
};

#endif // EMPLOYEE_H

