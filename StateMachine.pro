#-------------------------------------------------
#
# Project created by QtCreator 2017-02-12T22:34:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StateMachine
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    StateMachine/MachineControl.cpp \
    StateMachine/StateControl.cpp \
    StateMachine/MachineBase.cpp \
    StateMachine/StateMachineControl.cpp \
    StateMachine/StateBase.cpp \
    StateMachine/StateMachineBase.cpp \
    StateMachine/Messages.cpp \
    StateMachine/ManagerMessages.cpp \
    StateMachine/ManagerMessagesControl.cpp

HEADERS  += \
    StateMachine/MachineControl.h \
    StateMachine/StateControl.h \
    StateMachine/MachineBase.h \
    StateMachine/StateMachineControl.h \
    StateMachine/StateBase.h \
    StateMachine/StateMachineBase.h \
    StateMachine/Messages.h \
    StateMachine/ManagerMessages.h \
    StateMachine/ManagerMessagesControl.h

FORMS    +=
