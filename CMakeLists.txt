cmake_minimum_required(VERSION 2.8)
# nombre del proyecto
project(gCovUsage C CXX)

include(FindPkgConfig)
include( CTest )

enable_testing()


# definicion de variables de entorno
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage -g -O0 --coverage ${CMAKE_CXX_FLAGS}")
add_subdirectory(src)
add_subdirectory(test)

