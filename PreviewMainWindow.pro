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
    optionsform.cpp \
    filesettings.cpp \
    outputstream.cpp

HEADERS  += mainwindow.h \
    startform.h \
    optionsform.h \
    filesettings.h \
    outputstream.h \
    splashscreen.h

FORMS    += mainwindow.ui \
    startform.ui \
    optionsform.ui \
    filesettings.ui

OTHER_FILES += \
    splash.png
