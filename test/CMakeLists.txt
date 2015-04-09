include(FindPkgConfig)
pkg_search_module(CPPTEST REQUIRED libcpptest)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(Test testrun.cpp expressiontest.cpp ${CMAKE_SOURCE_DIR}/expression.cpp)
target_link_libraries(Test ${CPPTEST_LIBRARIES})

