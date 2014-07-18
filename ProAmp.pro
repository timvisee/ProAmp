#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T17:32:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProAmp
TEMPLATE = app


SOURCES += proamp.cpp\
        mainwindow.cpp \
    core.cpp \
    logger.cpp \
    profiler.cpp

HEADERS  += proamp.h \
    mainwindow.h \
    core.h \
    logger.h \
    profiler.h

FORMS    += mainwindow.ui
