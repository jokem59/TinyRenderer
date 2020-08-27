cmake_minimum_required(VERSION 3.10)

# Project name
project(TGAImage VERSION 1.0)

# Add Static Library
add_library(TGAImage
            STATIC
            "${CMAKE_CURRENT_SOURCE_DIR}/tgaimage.cpp")

target_include_directories(TGAImage
                           PUBLIC
                           "${CMAKE_SOURCE_DIR}/inc")

if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  # Specify C++ standard
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif (UNIX)
