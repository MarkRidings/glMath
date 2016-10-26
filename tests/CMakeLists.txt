cmake_minimum_required(VERSION 3.6)

set(gtest_SOURCE_DIR /home/mark/lib/google_test/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/inclue {gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES vecTests.cpp matTests.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})

target_link_libraries(runTests gtest glMath pthread)
