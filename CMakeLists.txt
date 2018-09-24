cmake_minimum_required(VERSION 3.1)

set(CMAKE_MODULE_PATH {CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/CMakeModules)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED HINTS ~/Qt/5.11.0/gcc_64)
find_package(Qt5Sql REQUIRED HINTS ~/Qt/5.11.0/gcc_64)

include_directories(src)

add_subdirectory(src)



if(UNIX)
    include(CodeCoverage)
endif()