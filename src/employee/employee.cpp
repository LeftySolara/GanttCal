#include "employee.h"
// #define SHIFT_NOT_FOUND 1

Employee::Employee(int id, const char *first, const char *last, const char *color)
{
  id_ = id;
  first_name_ = first;
  last_name_ = last;
  display_color_ = color;
}

Employee::~Employee()
{
  shifts_.clear();
}

void Employee::add_shift(Days day, time_t start, time_t end)
{
  // if (start > end)
  //   return INVALID_INPUT_FORMAT;
  Shift *new_shift = new Shift;
  new_shift->day = day;
  new_shift->start_time = start;
  new_shift->end_time = end;
  shifts_.push_back(*new_shift);
}

void Employee::remove_shift(Days day, time_t start)
{
  // int lim = shifts_.size();
  // for (auto i = shifts_.begin(); i != shifts_.end(); ++i) {
  //   if (*i.day == day && *i.start_time == start) {
  //     shifts_.erase(i);
  //     // return 0;
  //   }
  // }
  // return SHIFT_NOT_FOUND;
}

double Employee::hours()
{
  double hours = 0.0;
  for (Shift s : shifts_) {
    time_t seconds = s.end_time - s.start_time;
    hours += (seconds / 360);
  }
  return hours;
}
