#include "catch.hpp"
#include "../include/database.h"

TEST_CASE ("database connections can be created", "[database, creation]") {

  Database *testDb = new Database("employee_test.db");
  REQUIRE( testDb->error_check() == false );
  delete testDb;
}
