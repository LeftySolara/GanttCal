#include "shift.h"
using std::ostream;


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
