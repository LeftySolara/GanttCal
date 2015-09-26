OBJ = database.o employee.o catch_include.o create_db.o execute_sql.o

test/alltests: $(OBJ)
	g++ -std=c++11 -lsqlite3 -o test/alltests $(OBJ)

database.o: src/database.cpp include/database.h
	g++ -c -std=c++11 src/database.cpp

employee.o: src/employee.cpp include/employee.h
	g++ -c -std=c++11 src/employee.cpp

catch_include.o: test/catch_include.cpp
	g++ -c -std=c++11 test/catch_include.cpp

create_db.o: test/create_db.cpp include/database.h
	g++ -c -std=c++11 test/create_db.cpp

execute_sql.o: test/execute_sql.cpp include/database.h
	g++ -c -std=c++11 test/execute_sql.cpp

.PHONY: clean
clean:
	rm test/alltests $(OBJ) *.db