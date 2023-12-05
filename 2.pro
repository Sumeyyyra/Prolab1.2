QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminpanel.cpp \
    airplane.cpp \
    bus.cpp \
    company.cpp \
    companypanel.cpp \
    customerpanel.cpp \
    main.cpp \
    mainwindow.cpp \
    route.cpp \
    train.cpp \
    user.cpp \
    vehicle.cpp

HEADERS += \
    ILoginable.h \
    admin.h \
    adminpanel.h \
    airplane.h \
    bus.h \
    company.h \
    companypanel.h \
    customerpanel.h \
    mainwindow.h \
    route.h \
    train.h \
    user.h \
    vehicle.h

FORMS += \
    adminpanel.ui \
    companypanel.ui \
    customerpanel.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
