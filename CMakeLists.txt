cmake_minimum_required(VERSION 3.10)

# Project name
project(TinyRenderer VERSION 1.0)

# Add exectuable
add_executable(TinyRenderer
               src/TinyRenderer.cpp)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

target_include_directories(Logger PUBLIC
                           "${CMAKE_SOURCE_DIR}/inc"
                           )


if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

# Make top-level CMakeLists aware of sub-CMakeLists
add_subdirectory("${CMAKE_SOURCE_DIR}/test")
