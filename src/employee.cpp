#include "../include/employee.h"
// #define SHIFT_NOT_FOUND 1

Employee::Employee(int idNum, const char *first, const char *last, const char *color)
{
  id = idNum;
  firstName = first;
  lastName = last;
  displayColor = color;
}

Employee::~Employee()
{
  shifts.clear();
}

void Employee::add_shift(Days day, time_t start, time_t end)
{
  // if (start > end)
  //   return INVALID_INPUT_FORMAT;
  Shift *newShift = new Shift;
  newShift->day = day;
  newShift->startTime = start;
  newShift->endTime = end;
  shifts.push_back(*newShift);
}

void Employee::remove_shift(Days day, time_t start)
{
  // int lim = shifts.size();
  // for (auto i = shifts.begin(); i != shifts.end(); ++i) {
  //   if (*i.day == day && *i.startTime == start) {
  //     shifts.erase(i);
  //     // return 0;
  //   }
  // }
  // return SHIFT_NOT_FOUND;
}

double Employee::hours_count()
{
  double hours = 0.0;
  for (Shift s : shifts) {
    time_t seconds = s.endTime - s.startTime;
    hours += (seconds / 360);
  }
  return hours;
}
