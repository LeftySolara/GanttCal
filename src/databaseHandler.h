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
  int execute(const char *stmt, void *callbackArg=0, char *zErrMsg=0);
  bool error_check();
};

#endif // DATABASE_HANDLER_H
