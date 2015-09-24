#include "../include/database.h"
#include <stdio.h>

Database::Database(const char *databaseName)
{
  int open_db_status = sqlite3_open(databaseName, &db);
  errMsgs.push_back(open_db_status);

  // enable foreign keys in sqlite3
  sqlite3_db_config(db, SQLITE_DBCONFIG_ENABLE_FKEY, 1);
}

Database::~Database()
{
  int close_db_status = sqlite3_close(db);
  errMsgs.push_back(close_db_status);
}

// Callback function for sqlite3_exec() calls that return two or more rows of data
int Database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  for (int i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
}

// Wrapper for executing SQL statements with sqlite3
// Parameters:
//    1) const char *stmt: the SQL statement to be executed
//    2) void *callback_arg: first argument to callback function
//    3) char *zErrMsg: error code to return from sqlite3_exec() call
// Returns error code for sqlite3_exec()
int Database::execute(const char *stmt, void *callbackArg, char *zErrMsg)
{
  int exec_status = sqlite3_exec(db, stmt, callback, callbackArg, &zErrMsg);
  errMsgs.push_back(exec_status);
  return exec_status;
}

// report whether any errors occured
// if errors present, returns true; otherwise returns false
bool Database::error_check()
{
  for (int i = 0; i < errMsgs.size(); ++i) {
    if (errMsgs[i] != 0) {
      return true;
    }
  }
  return false;
}
