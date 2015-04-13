include(FindPkgConfig)
pkg_search_module(CPPTEST REQUIRED libcpptest)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

include_directories(${SRC_DIR})



add_executable(Test testrun.cpp expressiontest.cpp ${SRC_DIR}/expression.cpp)
target_link_libraries(Test ${CPPTEST_LIBRARIES})

