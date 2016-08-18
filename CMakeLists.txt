cmake_minimum_required(VERSION 3.3)
project(ThereC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c src_hlp/readFile.c helper/readFile.h src_hlp/basic.c helper/basic.h src_hlp/dependant.c helper/dependant.h helper/common.h)
add_executable(ThereC ${SOURCE_FILES})