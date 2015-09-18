#define CATCH_CONFIG_MAIN   // tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/databaseHandler.h"

TEST_CASE ("database connections can be created and closed", "[database]") {

  const char *dbName = "employee_test.db";
  sqlite3 *db;

  REQUIRE( sqlite3_open(dbName, &db) == 0 );
  REQUIRE( sqlite3_close(db) == 0 );
}
