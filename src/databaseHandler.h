// a wrapper for the sqlite3 api

#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <sqlite3.h>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;

class DatabaseHandler
{
private:
  sqlite3 *db;
  vector<string> columns;
  vector<char*> errMsgs;  // error codes for sqlite calls
public:
  typedef vector<pair<string,string>> column;
  DatabaseHandler(const char *databaseName);
  ~DatabaseHandler();
  // int create_table(string tblName, vector<column> columns);
};

#endif // DATABASE_HANDLER_H
