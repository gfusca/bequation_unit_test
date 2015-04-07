cmake_minimum_required(VERSION 2.8)

# nombre del proyecto
project(gCovUsage C CXX)

include(FindPkgConfig)
# definicion de variables de entorno
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

set(PROJECT_SRC main.cpp operator.cpp expression.cpp)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -g -O0 --coverage ${CMAKE_CXX_FLAGS}")
pkg_search_module(CPPUNIT REQUIRED cppunit)

add_executable(bool_eval ${PROJECT_SRC})
add_definitions(-fprofile-arcs -ftest-coverage)
target_link_libraries(bool_eval ${CPPUNIT_LIBRARIES})
