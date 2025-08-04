file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cpp)

add_library(test_framework STATIC ${SRC_FILES})

target_include_directories(test_framework PUBLIC ${PROJECT_INCLUDE_DIR})

target_compile_options(test_framework PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Werror -pedantic -g>
    $<$<CONFIG:Release>:-O2>
)
