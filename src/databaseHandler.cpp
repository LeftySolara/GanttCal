#include "databaseHandler.h"

DatabaseHandler::DatabaseHandler(string databaseName)
{
  int open_db_status = sqlite3_open(databaseName, &db);
  errMsgs.push_back(open_db_status);
}

DatabaseHandler::~DatabaseHandler()
{
  int close_db_status = sqlite3_close(db);
  errMsgs.push_back(close_db_status);
}
