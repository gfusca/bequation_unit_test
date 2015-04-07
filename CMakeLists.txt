cmake_minimum_required(VERSION 2.8)

# nombre del proyecto
project(gCovUsage C CXX)

include(FindPkgConfig)
# definicion de variables de entorno
set(CMAKE_CXX_FLAGS "-fprofile-arcs -ftest-coverage ${CMAKE_CXX_FLAGS}")
set(PROJECT_SRC main.cpp operator.cpp expression.cpp)

pkg_search_module(CPPUNIT REQUIRED cppunit)

add_executable(bool_eval ${PROJECT_SRC})

target_link_libraries(bool_eval ${CPPUNIT_LIBRARIES})
