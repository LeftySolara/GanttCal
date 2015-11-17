/* Copyright (C) 2015 Jalen Adams
 *
 * Authors: Jalen Adams <leftysolara@gmail.com>
 *
 * This file is part of GanttCal.
 *
 * GanttCal is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GanttCal is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GanttCal.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

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
