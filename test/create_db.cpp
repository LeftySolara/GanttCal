#include "catch.hpp"
#include "../include/database.h"

TEST_CASE ("database connections can be created", "[database, creation]") {

  Database *test_db = new Database("employee_test.db");
  REQUIRE( test_db->error_check() == false );
  delete test_db;
}
