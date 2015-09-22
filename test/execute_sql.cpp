#include "catch.hpp"
#include "../include/databaseHandler.h"

SCENARIO( "SQL statements can be evaluated using the DatabaseHandler wrapper",
  "[database, sql, DatabaseHandler, wrapper]" )
{
  GIVEN( "A valid database connection" )
  {
    DatabaseHandler *testDB = new DatabaseHandler("sql_exec.db");
    REQUIRE( testDB->error_check() == false );

    WHEN( "A CREATE TABLE statement is given" )
    {
      int create_status = testDB->execute("CREATE TABLE IF NOT EXISTS employees ("
        "first_name VARCHAR(25) NOT NULL,"
        "last_name VARCHAR(25) NOT NULL,"
        "department VARCHAR(50) NULL"
        ")");

      THEN ( "A table is created" )
      {
        // if the table doesn't exist, execute() will return 4
        int select_status = testDB->execute("SELECT * FROM employees");
        REQUIRE( create_status == 0 );
        REQUIRE( select_status == 0 );
      }
    }

    delete testDB;
  }
}
