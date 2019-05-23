#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T13:49:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = projet_couleur_rdf
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    camerawidget.cpp \
        main.cpp \
    classification.cpp \
    utilities.cpp \
    playlist.cpp \
    mainwindow.cpp
    playlist.cpp

HEADERS += \
    camerawidget.h \
        mainwindow.h \
    classification.h \
    utilities.h \
    playlist.h
    playlist.h

FORMS += \
        mainwindow.ui

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)/lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413 \
    -lopencv_objdetect2413

    haar.qrc
    base_music.qrc

RESOURCES += \
    base_music.qrc
