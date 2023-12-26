QT       += core gui
UIDIR     = ui/
METADIR   = meta/

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -lstdc++fs


SOURCES += \
    drawer/camera.cpp \
    drawer/light-source.cpp \
    engine/engine.cpp \
    drawer/qtdrawer.cpp \
    drop/drop.cpp \
    main.cpp \
    primitive/polygon.cpp \
    ui/main-window.cpp \
    ui/silent-mode.cpp

HEADERS += \
    drawer/camera.h \
    drawer/light-source.h \
    engine/engine.h \
    drawer/qtdrawer.h \
    drop/drop.h \
    primitive/polygon.h \
    ui/main-window.h \
    ui/silent-mode.h

FORMS += \
    meta/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

silent.TARGET = /tmp/$${TARGET}/bin
silent.commands = ./drop-simulator -silent

#filmtarget.TARGET = /tmp/$${TARGET}/bin
filmtarget.commands = python3 ../makefilm.py
filmtarget.depends = drop-simulator silent

QMAKE_EXTRA_TARGETS += filmtarget silent

