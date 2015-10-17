PRAGMA foreign_keys = ON;

CREATE TABLE employees (
    employee_id INT NOT NULL PRIMARY KEY,
    last_name VARCHAR(45) NOT NULL,
    first_name VARCHAR(45) NOT NULL,
    max_hours SMALLINT NULL
    schedule_color VARCHAR(7) NULL
    );

-- Create table for possible days and populate it
CREATE TABLE weekdays (
    weekday_id SMALLINT NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL UNIQUE
    );

INSERT INTO weekdays VALUES (0, "Sunday");
INSERT INTO weekdays VALUES (1, "Monday");
INSERT INTO weekdays VALUES (2, "Tuesday");
INSERT INTO weekdays VALUES (3, "Wednesday");
INSERT INTO weekdays VALUES (4, "Thursday");
INSERT INTO weekdays VALUES (5, "Friday");
INSERT INTO weekdays VALUES (6, "Saturday");

CREATE TABLE shifts (
    shift_id INT NOT NULL PRIMARY KEY,
    workday_id SMALLINT NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    length SMALLINT NOT NULL,
    employee_id INT NOT NULL,
    FOREIGN KEY (workday_id) REFERENCES weekdays(weekday_id),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
    );

COMMIT
