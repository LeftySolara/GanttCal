// a wrapper for the sqlite3 api

#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <sqlite3.h>

class DatabaseHandler
{
private:
  sqlite3 *db;
  vector<string> columns;
  vector<int> errMsgs;  // error codes for sqlite calls
public:
  typedef vector<pair<string,string>> column;
  DatabaseHandler(const char *databaseName);
  ~DatabaseHandler();
  bool error_check();
  // int create_table(string tblName, vector<column> columns);
};

#endif // DATABASE_HANDLER_H
