# C versions
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(num-conv VERSION 1.0)

# File
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE /usr/local/bin/)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(num-conv main.cpp ${SRC_FILES})
target_include_directories(num-conv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
