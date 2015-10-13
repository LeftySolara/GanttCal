#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T11:59:24
#
#-------------------------------------------------

QT       += core gui
QTPLUGIN += -plugin-sql-sqlite

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GanttCal
TEMPLATE = app


SOURCES +=\
    ../src/main.cpp \
    ../src/mainwindow.cpp \
    ../src/employee.cpp \
    ../src/addemployeedialog.cpp

HEADERS  += \
    ../include/mainwindow.h \
    ../include/employee.h \
    addemployeedialog.h \
    ../include/addemployeedialog.h \
    ../include/database.h

FORMS    += \
    ../Qt/mainwindow.ui \
    addemployeedialog.ui
