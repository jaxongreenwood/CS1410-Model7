cmake_minimum_required(VERSION 3.8)
project(Model7)

set(CMAKE_CXX_STANDARD 11)

#set(SOURCE_FILES unary.cpp)
set(SOURCE_FILES assignment.cpp)

add_executable(Model7 ${SOURCE_FILES})