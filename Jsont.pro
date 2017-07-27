#-------------------------------------------------
#
# Project created by QtCreator 2017-06-29T16:07:13
#
#-------------------------------------------------

QT      += core gui winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jsont
TEMPLATE = app

include(src/application/application.pri)
include(src/ui/ui.pri)

INCLUDEPATH += $$PWD/src/application
INCLUDEPATH += $$PWD/src/ui

RESOURCES += \
    resource.qrc
