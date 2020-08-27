cmake_minimum_required(VERSION 3.10)

# Project name
project(TinyRenderer VERSION 1.0)

# Add exectuable
add_executable(TinyRenderer
               "${CMAKE_SOURCE_DIR}/src/Renderer/TinyRenderer.cpp")

target_include_directories(TinyRenderer
                           PUBLIC
                           "${CMAKE_SOURCE_DIR}/inc")

if (UNIX)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  # Specify C++ standard
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif (UNIX)

# Make top-level CMakeLists aware of sub-CMakeLists
#add_subdirectory("${CMAKE_SOURCE_DIR}/src/Renderer")
add_subdirectory("${CMAKE_SOURCE_DIR}/src/TGAImage")

target_link_libraries(TinyRenderer TGAImage)
target_link_libraries(TinyRenderer "${CMAKE_SOURCE_DIR}/lib/libLogger.a")
