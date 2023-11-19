QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += gui
QT += widgets

QT += network


CONFIG += c++11 console
CONFIG -= app_bundle


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
    main.cpp \
    mytcpclient.cpp \
    mytcpserver.cpp

HEADERS += \
    mytcpclient.h \
    mytcpserver.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
