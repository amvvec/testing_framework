cmake_minimum_required(VERSION 3.10)
project(test_framework VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pedantic -Wall -Werror -Wextra")

################################################################################

# # Include header directory
# include_directories(include)

# # Find all sources
# file(GLOB SRC_FILE src/*.cpp)
# file(GLOB TEST_FILES tests/*.cpp)

# # Create executable file
# add_executable(launch ${SRC_FILE} ${TEST_FILES})

# # Create lib
# file(GLOB UNIT_SRC ${SRC_FILE}) # WARNING: edit this shit
# add_library(unit STATIC ${UNIT_SRC})

# target_include_directories(unit PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/include
# )

# # Preventing re-addition
# if(NOT TARGET unit)
#     add_library(unit STATIC ${UNIT_SRC})
# endif()

################################################################################
add_subdirectory(. test_framework_build)

file(GLOB TEST_FILES tests/*.cpp)

add_executable(launch ${TEST_FILES})

target_link_libraries(launch PRIVATE unit)
