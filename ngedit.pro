QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ngedit
TEMPLATE = app


SOURCES += main.cpp\
        editor.cpp

HEADERS  += editor.h

FORMS    += editor.ui
