cmake_minimum_required(VERSION 3.5)

set(SOURCES_SM
    ./MachineBase.cpp
    ./MachineControl.cpp
    ./ManagerMessages.cpp
    ./ManagerMessagesControl.cpp
    ./Messages.cpp
    ./StateBase.cpp
    ./StateControl.cpp
    ./StateMachineBase.cpp
    ./StateMachineControl.cpp
    ./MachineBase.cpp
)

add_library(SM_LIBS STATIC ${SOURCES_SM})  # Создание статической библиотеки
