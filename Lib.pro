#-------------------------------------------------
#
# Project created by QtCreator 2016-07-03T11:27:58
#
#-------------------------------------------------
include(Gemeinsam.pri)
QT       -= gui

TARGET = qalarm
TEMPLATE = lib

isEmpty(STATISCH) {
DEFINES += LIB_ERSTELLEN
}
else {
CONFIG += staticlib
}

defined(journal,var) {
DEFINES += JOURNAL_NUTZEN
LIBS	+= -lsystemd
}

SOURCES += Quellen/Konfiguration.cpp \
	   Quellen/Protokollierung.cpp\
	   Quellen/Websocket.cpp

HEADERS += Quellen/Konfiguration.h\
	   Quellen/qalarmlib_global.h \
	   Quellen/Protokollierung.h \
	   Quellen/Websocket.h

DISTFILES += srpm-bauen.sh\
	     qalarm-lib.spec
