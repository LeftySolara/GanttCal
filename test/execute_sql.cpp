// Unit tests for executing SQL statements using database wrapper
// Tests:
//    - creating a table
//    - inserting values into a table

#include "catch.hpp"
#include "../include/database.h"

SCENARIO( "SQL statements can be evaluated using the Database wrapper",
  "[database, sql, wrapper]" )
{
  GIVEN( "A valid database connection" )
  {
    Database *testDB = new Database("sql_exec.db");
    REQUIRE( testDB->error_check() == false );

    WHEN( "A CREATE TABLE statement is given" )
    {
      int create_status = testDB->execute("CREATE TABLE IF NOT EXISTS employees ("
        "first_name VARCHAR(25) NOT NULL,"
        "last_name VARCHAR(25) NOT NULL,"
        "department VARCHAR(50) NULL"
        ")");

      THEN( "A table is created" )
      {
        // if the table doesn't exist, testDB->execute() will return 4
        int select_status = testDB->execute("SELECT * FROM employees");
        REQUIRE( create_status == 0 );
        REQUIRE( select_status == 0 );
      }
    }

    WHEN( "INSERT INTO statements are given" )
    {
      int insert_status1 = testDB->execute("INSERT INTO employees VALUES ('Jenny','Smith','Marketing')");
      int insert_status2 = testDB->execute("INSERT INTO employees VALUES ('Matt','Johnson','Sales')");
      int insert_status3 = testDB->execute("INSERT INTO employees VALUES ('Martha','Washington','Shipping')");

      THEN( "The values are put into the database" )
      {
        REQUIRE( insert_status1 == 0 );
        REQUIRE( insert_status2 == 0 );
        REQUIRE( insert_status3 == 0 );
      }
    }
    delete testDB;
  }
}
