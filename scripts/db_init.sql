--
-- File generated with SQLiteStudio v3.0.6 on Fri Oct 23 23:47:19 2015
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table meta: holds info on the database itself
CREATE TABLE meta (
    version        REAL    NOT NULL ON CONFLICT ROLLBACK,
    employee_count INT     NOT NULL ON CONFLICT ROLLBACK
                           DEFAULT (0),
    shift_count    INT     NOT NULL ON CONFLICT ROLLBACK
                           DEFAULT (0),
    next_id        INT     DEFAULT (0)
                           NOT NULL ON CONFLICT ROLLBACK
);

INSERT INTO meta (version, employee_count, shift_count, next_id) VALUES (0.1, 0, 0, 0);


-- Table weekday: just a list of days
CREATE TABLE weekday (
    id_weekday INT          PRIMARY KEY ON CONFLICT ROLLBACK
                            NOT NULL ON CONFLICT ROLLBACK,
    name       VARCHAR (10) NOT NULL ON CONFLICT ROLLBACK
                            UNIQUE ON CONFLICT ROLLBACK
);

INSERT INTO weekday (id_weekday, name) VALUES (0, 'Sunday');
INSERT INTO weekday (id_weekday, name) VALUES (1, 'Monday');
INSERT INTO weekday (id_weekday, name) VALUES (2, 'Tuesday');
INSERT INTO weekday (id_weekday, name) VALUES (3, 'Wednesday');
INSERT INTO weekday (id_weekday, name) VALUES (4, 'Thursday');
INSERT INTO weekday (id_weekday, name) VALUES (5, 'Friday');
INSERT INTO weekday (id_weekday, name) VALUES (6, 'Saturday');

-- Table employee
CREATE TABLE employee (
    id_employee   INT         PRIMARY KEY ON CONFLICT ROLLBACK
                              NOT NULL ON CONFLICT ROLLBACK
                              DEFAULT (0),
    last_name     TEXT        NOT NULL ON CONFLICT ROLLBACK,
    first_name    TEXT        NOT NULL ON CONFLICT ROLLBACK,
    max_hours     INT         NOT NULL ON CONFLICT ROLLBACK
                              DEFAULT (0),
    displayed     BOOLEAN     NOT NULL ON CONFLICT ROLLBACK
                              DEFAULT (1),
    display_color VARCHAR (7) DEFAULT ('869AE9')
                              NOT NULL ON CONFLICT ROLLBACK
);


-- Table shift
CREATE TABLE shift (
    id_shift    INT  PRIMARY KEY ON CONFLICT ROLLBACK
                     NOT NULL ON CONFLICT ROLLBACK,
    day         INT  REFERENCES weekday (id_weekday)
                     NOT NULL ON CONFLICT ROLLBACK,
    start_time  TIME NOT NULL ON CONFLICT ROLLBACK,
    end_time    TIME NOT NULL ON CONFLICT ROLLBACK,
    employee_id INT  REFERENCES employee (id_employee)
                     NOT NULL ON CONFLICT ROLLBACK
);


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
