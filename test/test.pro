include(../defaults.pri)
QT += core
TEMPLATE = app

CONFIG   += console C++11
CONFIG   -= app_bundle
#CONFIG   -= qt

SOURCES += \
    main.cpp \
    shifts.cpp \
    ../src/shift/shift.cpp

HEADERS += catch.hpp \
    ../src/shift/shift.h
