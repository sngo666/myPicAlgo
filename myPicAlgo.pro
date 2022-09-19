QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp\
    dft.cpp\
    lsb.cpp


HEADERS += \
    mainwindow.h\
    dft.h\
    lsb.h


FORMS += \
    mainwindow.ui\
    dft.ui\
    lsb.ui


INCLUDEPATH += E:\opencv4.5.1\opencv\opencv-build\install\include
LIBS += E:\opencv4.5.1\opencv\opencv-build\lib\libopencv_*.dll.a

QMAKE_CXXFLAGS += -Wno-unused-parameter

QMAKE_CXXFLAGS += -Wno-unused-variable

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
