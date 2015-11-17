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
  bool is_valid();
  std::ostream& operator << (std::ostream& os, const Shift& rhs);
  bool operator == (const Shift& rhs) const;
  bool operator != (const Shift& rhs) const;
};

#endif // SHIFT_H

