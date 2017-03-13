#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T16:56:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kiulvira
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tag.cpp \
    file.cpp \
    directory.cpp \
    data.cpp

HEADERS  += mainwindow.hpp \
    tag.hpp \
    file.hpp \
    directory.hpp \
    data.hpp

FORMS    += mainwindow.ui
