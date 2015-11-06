QT       += core gui sql
QTPLUGIN += -plugin-sql-sqlite

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GanttCal
INCLUDEPATH += src
CONFIG += C++11
TEMPLATE = app

SOURCES += \
  src/database/database.cpp \
  src/employee/employee.cpp \
  src/ui/addemployeedialog.cpp \
  src/ui/mainwindow.cpp \
  src/utility/utility.cpp \
  src/main.cpp

HEADERS += \
  src/database/database.h \
  src/employee/employee.h \
  src/ui/addemployeedialog.h \
  src/ui/mainwindow.h \
  src/utility/utility.h \
  src/main.h

FORMS += \
  src/ui/addemployeedialog.ui \
  src/ui/mainwindow.ui

OTHER_FILES += \
    scripts/db_init.sql
