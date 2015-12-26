include(../defaults.pri)
QT += core sql
TEMPLATE = app

CONFIG   += console C++11
CONFIG   -= app_bundle
#CONFIG   -= qt

SOURCES += \
    main.cpp \
    shifts.cpp \
    employees.cpp \
    employeetablemodel_tests.cpp \
    ../src/shift/shift.cpp \
    ../src/employee/employee.cpp \
    ../src/models/employeetablemodel.cpp \
    ../src/utility/utility.cpp

HEADERS += catch.hpp \
    ../src/shift/shift.h \
    ../src/models/employeetablemodel.h
