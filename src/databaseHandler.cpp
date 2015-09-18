#include "databaseHandler.h"

DatabaseHandler::DatabaseHandler(const char *databaseName)
{
  int open_db_status = sqlite3_open(databaseName, &db);
  errMsgs.push_back(open_db_status);
}

DatabaseHandler::~DatabaseHandler()
{
  int close_db_status = sqlite3_close(db);
  errMsgs.push_back(close_db_status);
}

// report whether any errors occured
// if errors present, returns true; otherwise returns false
bool DatabaseHandler::error_check()
{
  for (int i = 0; i < errMsgs.size(); ++i) {
    if (errMsgs[i] != 0) {
      return true;
    }
  }
  return false;
}
