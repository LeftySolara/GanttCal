// a small wrapper for the sqlite3 C++ api

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <sqlite3.h>

class Database
{
private:
  sqlite3 *db_;
  std::vector<int> error_messages_;  // error codes for sqlite3 calls
public:
  Database(const char *file_name);
  ~Database();
  static int callback(void *NotUsed, int argc, char **argv, char** azColName);
  int execute(const char *stmt, void *callback_arg=0, char *zErrMsg=0);
  bool error_check();
};

#endif // DATABASE_H
