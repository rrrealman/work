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
    outputstreamobject.cpp \
    output.cpp \
    youtubeoutput.cpp \
    ustreamoutput.cpp \
    hostoutput.cpp \
    application.cpp \
    hostoutputvarparams.cpp \
    youtubeoutputvarparams.cpp

HEADERS  += mainwindow.h \
    startform.h \
    optionsform.h \
    filesettings.h \
    splashscreen.h \
    outputstreamobject.h \
    output.h \
    youtubeoutput.h \
    ustreamoutput.h \
    hostoutput.h \
    application.h \
    hostoutputvarparams.h \
    youtubeoutputvarparams.h

FORMS    += mainwindow.ui \
    startform.ui \
    optionsform.ui \
    filesettings.ui \
    hostoutputvarparams.ui \
    youtubeoutputvarparams.ui

OTHER_FILES +=
