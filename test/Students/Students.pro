#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T17:58:13
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Students
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    student.cpp

HEADERS  += mainwindow.h \
    student.h \
    list.h \
    node.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++0x
