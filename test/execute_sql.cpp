// Unit tests for executing SQL statements using database wrapper
// Tests:
//    - creating a table
//    - inserting values into a table
//    - deleting values from a table

#include "catch.hpp"
#include "../include/database.h"

SCENARIO( "SQL statements can be evaluated using the Database wrapper",
  "[database, sql, wrapper]" )
{
  GIVEN( "A valid database connection" )
  {
    Database *test_db = new Database("sql_exec.db");
    REQUIRE( test_db->error_check() == false );

    WHEN( "A CREATE TABLE statement is given" )
    {
      int create_exit_status = test_db->execute("CREATE TABLE IF NOT EXISTS employees ("
        "first_name VARCHAR(25) NOT NULL,"
        "last_name VARCHAR(25) NOT NULL,"
        "department VARCHAR(50) NULL"
        ")");

      THEN( "A table is created" )
      {
        // if the table doesn't exist, test_db->execute() will return 4
        int select_exit_status = test_db->execute("SELECT * FROM employees");
        REQUIRE( create_exit_status == 0 );
        REQUIRE( select_exit_status == 0 );
      }
    }

    WHEN( "INSERT INTO statements are given" )
    {
      int insert_exit_status_1 = test_db->execute("INSERT INTO employees VALUES ('Jenny','Smith','Marketing')");
      int insert_exit_status_2 = test_db->execute("INSERT INTO employees VALUES ('Matt','Johnson','Sales')");
      int insert_exit_status_3 = test_db->execute("INSERT INTO employees VALUES ('Martha','Washington','Shipping')");

      THEN( "The values are put into the database" )
      {
        REQUIRE( insert_exit_status_1 == 0 );
        REQUIRE( insert_exit_status_2 == 0 );
        REQUIRE( insert_exit_status_3 == 0 );
        test_db->execute("SELECT * FROM employees");
      }
    }

    WHEN ( "A DELETE statement is given" )
    {
      int delete_exit_status = test_db->execute("DELETE FROM employees WHERE last_name = 'Johnson'");

      THEN ( "The specified row is removed" )
      {
        REQUIRE( delete_exit_status == 0 );
        test_db->execute("SELECT * FROM employees");
      }
    }
    delete test_db;
  }
}
