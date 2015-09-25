#include "../include/database.h"
#include <stdio.h>

Database::Database(const char *file_name)
{
  int *f_keys_enabled;
  int open_exit_status = sqlite3_open(file_name, &db_);
  int config_exit_status = sqlite3_db_config(db_, SQLITE_DBCONFIG_ENABLE_FKEY, 1, &f_keys_enabled);

  if (open_exit_status != SQLITE_OK)
    error_messages_.push_back(open_exit_status);
  if (config_exit_status != SQLITE_OK)
    error_messages_.push_back(config_exit_status);
}

Database::~Database()
{
  int close_exit_status = sqlite3_close(db_);

  if (close_exit_status != SQLITE_OK)
    error_messages_.push_back(close_exit_status);
}

// Callback function for sqlite3_exec()
// Executed when a query returns more than one row and runs for each row returned
int Database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  for (int i = 0; i < argc; ++i)
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

  printf("\n");
  return 0;
}

// Wrapper for executing SQL statements with sqlite3
// Parameters:
//    1) const char *stmt: the SQL statement to be executed
//    2) void *callback_arg: first argument to callback function (defaults to 0)
//    3) char *zErrMsg: error code to return from sqlite3_exec() (defaults to 0)
int Database::execute(const char *stmt, void *callback_arg, char *zErrMsg)
{
  int exec_exit_status = sqlite3_exec(db_, stmt, callback, callback_arg, &zErrMsg);
  error_messages_.push_back(exec_exit_status);
  return exec_exit_status;
}

// report whether any errors occured
// if errors present, returns true; otherwise returns false
bool Database::error_check()
{
  for (int i = 0; i < error_messages_.size(); ++i) {
    if (error_messages_[i] != SQLITE_OK)
      return true;
  }
  return false;
}
