# C versions
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project name
project(num-conv VERSION 1.0)

# File
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(num-conv main.cpp ${SRC_FILES})
target_include_directories(num-conv PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(BUILD_FOR_WIN TRUE)
endif()
option(STATIC_BUILD "Build a static binary." ${BUILD_FOR_WIN})

if (STATIC_BUILD)
        set(CMAKE_EXE_LINKER_FLAGS "-static")
        set(CMAKE_FIND_LIBRARY_SUFFIXES ".a" CONFIG)
        set(BUILD_SHARED_LIBS OFF)
endif()

install (TARGETS ${PROJECT_NAME} DESTINATION /usr/local/bin CONFIGURATIONS build-linux)

# Testing (only available for linux since I don't know how to do it in windows)
if (NOT BUILD_FOR_WIN)
	include(CTest)
	find_package(GTest REQUIRED)
	project(num-conv-test VERSION 1.0)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)
	add_executable(num-conv-test ./tests/conversion-tests.cpp ${SRC_FILES})
	target_include_directories(num-conv-test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
	target_link_libraries(num-conv-test ${GTEST_LIBRARIES})
	enable_testing()
	add_test(NAME num-conv-test COMMAND num-conv-test)
endif()
