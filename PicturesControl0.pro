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
    crecord.cpp \
    #programm/debug/moc_mainwindow.cpp \
    #programm/moc_mainwindow.cpp
    fmview.cpp \
    cimportfiles.cpp

HEADERS  += mainwindow.h \
    cinifile.h \
    crecord.h \
    #programm/moc_predefs.h \
    #programm/ui_mainwindow.h
    fmview.h \
    cimportfiles.h

FORMS    += mainwindow.ui \
    fmview.ui

RESOURCES += \
    resourcedata.qrc
