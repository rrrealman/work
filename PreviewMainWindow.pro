#-------------------------------------------------
#
# Project created by QtCreator 2015-07-06T06:40:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PreviewMainWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    startform.cpp \
    shareform.cpp \
    optionsform.cpp

HEADERS  += mainwindow.h \
    startform.h \
    shareform.h \
    optionsform.h

FORMS    += mainwindow.ui \
    startform.ui \
    shareform.ui \
    optionsform.ui
