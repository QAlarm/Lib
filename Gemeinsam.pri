QT	     += websockets
CONFIG	     += c++11 no_keywords
DESTDIR	     = bin
UI_DIR	     = tmp/ui
MOC_DIR	     = tmp/moc
OBJECTS_DIR  = tmp/obj
RCC_DIR	     = tmp/rcc
QMAKE_LFLAGS += -fuse-ld=gold
