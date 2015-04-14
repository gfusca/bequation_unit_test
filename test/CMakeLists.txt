include(FindPkgConfig)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(GMOCK_LIB_DIR "/usr/local/lib/libgmock.so")

include_directories(${SRC_DIR})
include_directories(${GTEST_INCLUDE_DIR})

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

SET(SRC_SOURCES ${SRC_DIR}/expression.cpp ${SRC_DIR}/expressionparser.cpp ${SRC_DIR}/operator.cpp)
add_executable(Test testrun.cpp expressiontest.cpp ${SRC_SOURCES})
target_link_libraries(Test ${GTEST_LIBRARY})
target_link_libraries(Test ${GMOCK_LIB_DIR})
target_link_libraries(Test ${CMAKE_THREAD_LIBS_INIT})
add_test(RunAllUnitTest Test)
