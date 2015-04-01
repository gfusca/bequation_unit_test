cmake_minimum_required(VERSION 2.8)

# nombre del proyecto
project(gCovUsage)

# definicion de variables de entorno
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage ${CMAKE_CXX_FLAGS}")
set(PROJECT_SRC main.cpp)

add_executable(gocv_usage ${PROJECT_SRC})
