#-------------------------------------------------
#
# Project created by QtCreator 2014-07-17T17:32:13
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProAmp
TEMPLATE = app


SOURCES += proamp.cpp\
        mainwindow.cpp \
    core.cpp \
    logger.cpp \
    profiler.cpp \
    aboutdialog.cpp \
    musicplayer.cpp \
    musicplayermanager.cpp

HEADERS  += proamp.h \
    mainwindow.h \
    core.h \
    logger.h \
    profiler.h \
    aboutdialog.h \
    musicplayer.h \
    musicplayermanager.h

FORMS    += mainwindow.ui \
    aboutdialog.ui
