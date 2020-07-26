
QT    +=core gui
greaterThan(QT_MAJOR_VERSION,4):QT += widgets serialport

HEADERS += \
    cwidgetserialtx.h \
    layoutDraw.h \
    qwidgetdemo.h \
    qwidgetdraw.h \
    qwidgetserialrx.h \
    wave.h

SOURCES += \
    cwidgetserialtx.cpp \
    layoutDraw.cpp \
    main.cpp \
    qwidgetdemo.cpp \
    qwidgetdraw.cpp \
    qwidgetserialrx.cpp

