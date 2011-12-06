CONFIG += release
TARGET = stopspamplugin
include(../../psiplugin.pri)
SOURCES += stopspamplugin.cpp \
    senddialog.cpp \
    jiditemmodel.cpp

HEADERS += \
    senddialog.h \
    jiditemmodel.h
FORMS += options.ui \
    senddialog.ui
