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
  int lim = shifts.size();
  for (int i = 0; i < lim; ++i) {
    delete shifts[i];
  }
  shifts.clear();
}

void Employee::add_shift(Days day, time_t start, time_t end)
{
  // if (start > end)
  //   return INVALID_INPUT_FORMAT;
  Shift newShift = new Shift;
  newShift->day = day;
  newShift->startTime = start;
  newShift->endTime = end;
  shifts.push_back(newShift);
}

int Employee::remove_shift(Days day, time_t start)
{
  int lim = shifts.size();
  for (int i = 0; i < lim; ++i) {
    if (shifts[i].day == day && shifts[i].startTime == start) {
      shifts.erase(i);
      // return 0;
    }
  }
  // return SHIFT_NOT_FOUND;
}
