CONFIG += release
TARGET = stopspamplugin
include(../../psiplugin.pri)
SOURCES += stopspamplugin.cpp \
    senddialog.cpp

HEADERS += \
    senddialog.h
FORMS += options.ui \
    senddialog.ui
