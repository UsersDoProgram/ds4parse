QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
##c++11
CONFIG += c++20

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS+=-L/usr/lib/libhidapi-hidraw.so.0.0.0 -lhidapi-hidraw
LIBS+=/home/grodo/devDir/ds4parse/lib/DS4.o
INCLUDEPATH += /home/grodo/devDir/ds4parse/include
SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../resources/triangle.png \
    ../resources/xbtn.jpeg

RESOURCES += \
    resource-imgs.qrc
