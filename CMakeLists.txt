cmake_minimum_required(VERSION 3.6)
project(glMath)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -O3 -std=c++11")

add_subdirectory(src)
add_subdirectory(tests)
