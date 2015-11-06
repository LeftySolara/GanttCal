#include "utility.h"
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
           QString statement = "";
           while (!in.atEnd())
           {
              QString line = in.readLine();
              // ignore comments
              if (line.startsWith("--") || line.length() == 0)
                  continue;
              statement += line;
              if (statement.endsWith(";")) {
                  // remove semicolon at end
                  statement.chop(1);
                  if (qry->prepare(statement)) {
                      qry->exec();
                      statement = "";
                  }
                  else
                      return false;
              }
           }
           inputfile->close();
        }
        return true;
    }
}
