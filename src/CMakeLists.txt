cmake_minimum_required(VERSION 2.8)
# nombre del proyecto
project(gCovUsage C CXX)

include(FindPkgConfig)

# definicion de variables de entorno
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -g -O0 --coverage ${CMAKE_CXX_FLAGS}")
set(PROJECT_SRC main.cpp operator.cpp expression.cpp expressionparser.cpp)
add_executable(bool_eval ${PROJECT_SRC})
add_definitions(-fprofile-arcs -ftest-coverage)

