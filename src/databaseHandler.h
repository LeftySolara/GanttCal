// a wrapper for the sqlite3 api

#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <vector>
#include <utility>
#include <sqlite3.h>

class DatabaseHandler
{
private:
  sqlite3 *db;
  std::vector<int> errMsgs;  // error codes for sqlite calls
public:
  DatabaseHandler(const char *databaseName);
  ~DatabaseHandler();
  static int callback(void *NotUsed, int argc, char **argv, char** azColName);
  void execute_sql(const char *stmt, void *callbackArg, char *zErrMsg);
  bool error_check();
};

#endif // DATABASE_HANDLER_H
