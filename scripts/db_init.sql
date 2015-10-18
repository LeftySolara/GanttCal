PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS employees (
    employee_id INT NOT NULL PRIMARY KEY,
    last_name VARCHAR(45) NOT NULL,
    first_name VARCHAR(45) NOT NULL,
    max_hours SMALLINT NULL,
    schedule_color VARCHAR(7) NULL
    );

-- Create table for possible days and populate it
CREATE TABLE IF NOT EXISTS weekdays (
    weekday_id SMALLINT NOT NULL PRIMARY KEY,
    name VARCHAR(10) NOT NULL UNIQUE
    );

INSERT INTO weekdays(weekday_id,name)
SELECT 0, 'Sunday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 0 AND name = 'Sunday');

INSERT INTO weekdays(weekday_id,name)
SELECT 1, 'Monday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 1 AND name = 'Monday');

INSERT INTO weekdays(weekday_id,name)
SELECT 2, 'Tuesday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 2 AND name = 'Tuesday');

INSERT INTO weekdays(weekday_id,name)
SELECT 3, 'Wednesday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 3 AND name = 'Wednesday');

INSERT INTO weekdays(weekday_id,name)
SELECT 4, 'Thursday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 4 AND name = 'Thursday');

INSERT INTO weekdays(weekday_id,name)
SELECT 5, 'Friday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 5 AND name = 'Friday');

INSERT INTO weekdays(weekday_id,name)
SELECT 6, 'Saturday'
WHERE NOT EXISTS(SELECT 1 FROM weekdays WHERE weekday_id = 6 AND name = 'Saturday');

CREATE TABLE IF NOT EXISTS shifts (
    shift_id INT NOT NULL PRIMARY KEY,
    workday_id SMALLINT NOT NULL,
    start_time TIME NOT NULL,
    end_time TIME NOT NULL,
    length SMALLINT NOT NULL,
    employee_id INT NOT NULL,
    FOREIGN KEY (workday_id) REFERENCES weekdays(weekday_id),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
    );

