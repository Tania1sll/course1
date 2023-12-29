QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminmainwindow.cpp \
    agency.cpp \
    createcustomer.cpp \
    createinstructor.cpp \
    createroute.cpp \
    customer.cpp \
    dbmanager.cpp \
    instructor.cpp \
    main.cpp \
    mainwindow.cpp \
    openwindow.cpp \
    person.cpp \
    route.cpp \
    showinstructor.cpp \
    showroute.cpp \
    sqlitedbmanager.cpp \
    userlogin.cpp \
    userregistration.cpp

HEADERS += \
    adminmainwindow.h \
    agency.h \
    createcustomer.h \
    createinstructor.h \
    createroute.h \
    customer.h \
    dbmanager.h \
    instructor.h \
    mainwindow.h \
    openwindow.h \
    person.h \
    route.h \
    showinstructor.h \
    showroute.h \
    sqlitedbmanager.h \
    userlogin.h \
    userregistration.h

FORMS += \
    adminmainwindow.ui \
    createcustomer.ui \
    createinstructor.ui \
    createroute.ui \
    mainwindow.ui \
    openwindow.ui \
    showinstructor.ui \
    showroute.ui \
    userlogin.ui \
    userregistration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Share all project output files by directories
MOC_DIR = moc
RCC_DIR = rcc
UI_DIR = ui
unix:OBJECTS_DIR = unix
win32:OBJECTS_DIR = win32
macx:OBJECTS_DIR = mac

# If release-buid -> run windeploy applications, that will collect all the dlls
CONFIG(release, debug|release) {
    win32:QMAKE_POST_LINK = $$(QTDIR)/bin/windeployqt $$OUT_PWD/release
}

RESOURCES += \
    Resource.qrc
