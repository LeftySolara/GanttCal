#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T14:21:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GanttCal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newemployeewidget.cpp

HEADERS  += mainwindow.h \
    newemployeewidget.h

FORMS    += mainwindow.ui \
    newemployeewidget.ui
