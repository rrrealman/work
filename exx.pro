#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T11:24:33
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ex1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CXX = g++

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/release/ -lQt5GLib-2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/debug/ -lQt5GLib-2
else:unix: LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/ -lQt5GLib-2.0

INCLUDEPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/release/ -lQt5GStreamer-1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/debug/ -lQt5GStreamer-1
else:unix: LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/ -lQt5GStreamer-1.0

INCLUDEPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/release/ -lQt5GStreamerQuick-1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/debug/ -lQt5GStreamerQuick-1
else:unix: LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/ -lQt5GStreamerQuick-1.0

INCLUDEPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/release/ -lQt5GStreamerUi-1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/debug/ -lQt5GStreamerUi-1
else:unix: LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/ -lQt5GStreamerUi-1.0

INCLUDEPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/release/ -lQt5GStreamerUtils-1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/debug/ -lQt5GStreamerUtils-1
else:unix: LIBS += -L$$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu/ -lQt5GStreamerUtils-1.0

INCLUDEPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../usr/lib/QtGStreamer-1.2/lib/x86_64-linux-gnu

INCLUDEPATH += /usr/lib/QtGStreamer-1.2/include/Qt5GStreamer
