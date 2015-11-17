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

ostream& Shift::operator << (ostream& os, const Shift& rhs) const
{
    QString day;

    switch (rhs.day) {
    case SUNDAY:
        day = "Sunday";
        break;
    case MONDAY:
        day = "Monday";
        break;
    case TUESDAY:
        day = "Tuesday";
        break;
    case WEDNESDAY:
        day = "Wednesday";
        break;
    case THURSDAY:
        day = "Thursday";
        break;
    case FRIDAY:
        day = "Friday";
        break;
    case SATURDAY:
        day = "Saturday";
        break;
    default:
        day = "Unknown";
        break;
    }

    os << day
       << rhs.start_time.toString("hh:mm");
       << rhs.end_time.toString("hh:mm");
    return os;
}

bool Shift::operator == (const Shift& rhs) const
{
    return (day == rhs.day)
        && (start_time == rhs.start_time)
        && (end_time == rhs.end_time);
}

bool Shift::operator != (const Shift& rhs) const
{
    return (day != rhs.day)
        && (start_time != rhs.start_time)
        && (end_time != rhs.end_time);
}
