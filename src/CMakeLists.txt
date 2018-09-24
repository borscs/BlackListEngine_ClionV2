cmake_minimum_required(VERSION 3.12)

set(SOURCES
        main.cpp
        Database.cpp
        Engine.cpp
        EngineHandler.cpp
        JsonHelper.cpp
        Utils.h
        )

find_package(Qt5Core REQUIRED HINTS ~/Qt/5.11.0/gcc_64)
find_package(Qt5Sql REQUIRED HINTS ~/Qt/5.11.0/gcc_64)

add_executable(src ${SOURCES})

target_link_libraries(src Qt5::Core Qt5::Sql)