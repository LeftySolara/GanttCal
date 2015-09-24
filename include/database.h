// a wrapper for the sqlite3 api

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <utility>
#include <sqlite3.h>

class Database
{
private:
  sqlite3 *db;
  std::vector<int> errMsgs;  // error codes for sqlite calls
public:
  Database(const char *databaseName);
  ~Database();
  static int callback(void *NotUsed, int argc, char **argv, char** azColName);
  int execute(const char *stmt, void *callbackArg=0, char *zErrMsg=0);
  bool error_check();
};

#endif // DATABASE_H
