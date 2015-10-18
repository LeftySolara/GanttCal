#include "../include/utility.h"
#include <QtDebug>

namespace utility
{
    bool read_sql(QFile *inputfile, QSqlQuery *qry)
    {
        if (!inputfile->open(QIODevice::ReadOnly))
            return false;
        else
        {
           QTextStream in(inputfile);
           QString statement;
           while (!in.atEnd())
           {
              QString line = in.readLine();
              // ignore comments
              if (line.startsWith("--"))
                  continue;
              // assumes queries are separated by blank lines
              if (line.length() == 0)
                  statement = "";
              statement += line;
              if (statement.endsWith(";")) {
                  // remove semicolon at end
                  statement.chop(1);
                  if (qry->prepare(statement))
                      qry->exec();
                  else
                      return false;
              }
           }
           inputfile->close();
        }
        return true;
    }
}
