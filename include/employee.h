#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <vector>

enum Days {Sunday,Monday,Tuesday,Wednesday,Thursday,Friday,Saturday};

struct Shift
{
  unsigned short day;
  time_t startTime;
  time_t endTime;
};

class Employee
{
private:
  int id; // foreign key for shift table in database
  const char *displayColor;
  const char *firstName;
  const char *lastName;
  std::vector<Shift> shifts;
public:
  Employee(int id, const char *first, const char *last, const char *color='#FFFFFF');
  ~Employee();
  void add_shift(Days day, time_t start, time_t end);
  void remove_shift(Days day, time_t start);
  double hours_count();
  int shift_count() { return shifts.size(); }
};

#endif // EMPLOYEE_H

