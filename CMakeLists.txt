cmake_minimum_required(VERSION 3.10)
project(test_framework VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find all sources
file(GLOB_RECURSE SRC_FILE src/*.cpp)
file(GLOB_RECURSE TEST_FILES tests/*.cpp)

# Create executable file
add_executable(launch ${SRC_FILE} ${TEST_FILES})

# Include header directory
target_include_directories(launch PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# add_compile_options(-Wall -Wextra -Werror -pedantic -g)

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     message(STATUS "Build in Debug mode")
#     add_compile_options(-Wall -Wextra -Werror -pedantic -g)
# elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
#     message(STATUS "Build in Release mode")
#     add_compile_options(-O2)
# endif()

target_compile_options(launch PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Werror -pedantic -g>
    $<$<CONFIG:Release>:-O2>
)
