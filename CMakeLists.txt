cmake_minimum_required(VERSION 3.14)
project(PID-controller)

set(CMAKE_CXX_STANDARD 17)

# CMake policies
cmake_policy(SET CMP0022 NEW)

#SET ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

# External dependencies
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external)

# Location where external projects will be downloaded
set(DOWNLOAD_LOCATION "${CMAKE_CURRENT_BINARY_DIR}/downloads"
        CACHE PATH "Location where external projects will be downloaded.")
mark_as_advanced(DOWNLOAD_LOCATION)

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include_directories("${PROJECT_SOURCE_DIR}/include" include src)

add_library(PID
        src/PID.cpp)
