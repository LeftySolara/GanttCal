#ifndef UTILITY
#define UTILITY

#include <QFile>
#include <QSqlQuery>

namespace utility
{
    bool read_sql(QFile *inputfile, QSqlQuery *qry);
}

#endif // UTILITY

