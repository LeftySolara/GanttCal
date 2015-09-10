PRAGMA foreign_keys = ON;

CREATE TABLE employees (
    employee_id INT NOT NULL PRIMARY KEY,
    first_name VARCHAR(45) NOT NULL,
    last_name VARCHAR(45) NOT NULL,
    max_hours SMALLINT NULL
    schedule_color VARCHAR(7) NULL
    );

CREATE TABLE weekdays (
    weekday_id SMALLINT NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL UNIQUE
    );

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
