#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T11:27:58
#
#-------------------------------------------------
include(Gemeinsam.pri)
QT       -= gui

TARGET = qalarm
TEMPLATE = lib

DEFINES += LIB_ERSTELLEN

SOURCES += Quellen/Konfiguration.cpp \
    Quellen/Protokollierung.cpp

HEADERS += Quellen/Konfiguration.h\
	   Quellen/qalarmlib_global.h \
    Quellen/Protokollierung.h

DISTFILES += srpm-bauen.sh\
	     qalarm-lib.spec
