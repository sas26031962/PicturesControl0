#-------------------------------------------------
#
# Project created by QtCreator 2025-03-04T15:08:51
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++14 # Добавляем поддержку C++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PicturesControl0
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cinifile.cpp \
    crecord.cpp

HEADERS  += mainwindow.h \
    cinifile.h \
    crecord.h

FORMS    += mainwindow.ui
