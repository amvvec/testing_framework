cmake_minimum_required(VERSION 3.10)
project(test_framework VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pedantic -Wall")

# Include header directory
include_directories(include)

# Find all sources
file(GLOB SRC_FILES src/*.cpp)

# Create executable file
add_executable(launch ${SRC_FILES})
