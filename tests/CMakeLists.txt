file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS *.cpp)

add_executable(launch ${TEST_FILES})

target_include_directories(launch PRIVATE ${PROJECT_INCLUDE_DIR})
target_link_libraries(launch PRIVATE test_framework)

set_target_properties(launch PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_test(NAME launch_tests COMMAND launch)
