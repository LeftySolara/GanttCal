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
  int length();
};

 std::ostream& operator << (std::ostream& os, const Shift& rhs);
 bool operator == (const Shift& lhs, const Shift& rhs);
 bool operator != (const Shift& lhs, const Shift& rhs);

#endif // SHIFT_H

