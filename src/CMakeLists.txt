cmake_minimum_required(VERSION 3.6)

set(SOURCE_FILES vec.h mat.h)

add_library(glMath ${SOURCE_FILES})
set_target_properties(glMath PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(glMath GLEW)
