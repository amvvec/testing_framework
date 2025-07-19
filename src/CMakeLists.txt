file(GLOB_RECURSE SRC_FILE CONFIGURE_DEPENDS *.cpp)

add_library(test_framework STATIC ${SRC_FILE})

target_include_directories(test_framework PUBLIC ${PROJECT_INCLUDE_DIR})

target_compile_options(test_framework PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Werror -pedantic -g>
    $<$<CONFIG:Release>:-O2>
)

add_executable(launch main.cpp)
target_link_libraries(launch PRIVATE test_framework)
target_compile_options(launch PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Werror -pedantic -g>
    $<$<CONFIG:Release>:-O2>
)
