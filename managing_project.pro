QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adding_employee.cpp \
    changing_employee.cpp \
    employee.cpp \
    main.cpp \
    mainwindow.cpp \
    showing_employee.cpp

HEADERS += \
    adding_employee.h \
    changing_employee.h \
    employee.h \
    mainwindow.h \
    showing_employee.h

FORMS += \
    adding_employee.ui \
    changing_employee.ui \
    mainwindow.ui \
    showing_employee.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
