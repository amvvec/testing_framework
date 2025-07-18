file(GLOB_RECURSE TEST_FILE CONFIGURE_DEPENDS *.cpp)

add_executable(tests ${TEST_FILE})

target_link_libraries(tests PRIVATE test_framework)

target_compile_options(tests PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Werror -pedantic -g>
    $<$<CONFIG:Release>:-O2>
)

add_test(NAME UnitTests COMMAND tests)
