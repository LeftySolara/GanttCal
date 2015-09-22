#include "catch.hpp"
#include "../include/databaseHandler.h"

TEST_CASE ("database connections can be created", "[database, creation]") {

  DatabaseHandler *testDb = new DatabaseHandler("employee_test.db");
  REQUIRE( testDb->error_check() == false );
  delete testDb;
}
