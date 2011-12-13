#CONFIG += irelease
CONFIG += debug 
TARGET = massmailingplugin
include(../../psiplugin.pri)
SOURCES += massmailingplugin.cpp \
    senddialog.cpp \
    jiditemmodel.cpp

HEADERS += \
    senddialog.h \
    jiditemmodel.h
FORMS += \
    senddialog.ui
