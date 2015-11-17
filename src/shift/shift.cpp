#include "shift.h"
using std::ostream;

// Checks that start and end times are valid time formats and
// that the start time is earlier than the end time
bool Shift::is_valid()
{
    return start_time.isValid() && end_time.isValid() && (start_time < end_time);
}

// returns the number of seconds from the start time to the end time
int Shift::length()
{
  return start_time.secsTo(end_time);
}

ostream& operator << (ostream& os, const Shift& rhs)
{
    switch (rhs.day) {
    case SUNDAY:
        os << "Sunday";
        break;
    case MONDAY:
        os << "Monday";
        break;
    case TUESDAY:
        os << "Tuesday";
        break;
    case WEDNESDAY:
        os << "Wednesday";
        break;
    case THURSDAY:
        os << "Thursday";
        break;
    case FRIDAY:
        os << "Friday";
        break;
    case SATURDAY:
        os << "Saturday";
        break;
    default:
        os << "Unknown";
        break;
    }

    os << rhs.start_time.toString("hh:mm").constData()
       << rhs.end_time.toString("hh:mm").constData();
    return os;
}

bool operator == (const Shift& lhs, const Shift& rhs)
{
    return (lhs.day == rhs.day)
        && (lhs.start_time == rhs.start_time)
        && (lhs.end_time == rhs.end_time);
}

bool operator != (const Shift& lhs, const Shift& rhs)
{
    return (lhs.day != rhs.day)
        && (lhs.start_time != rhs.start_time)
        && (lhs.end_time != rhs.end_time);
}
