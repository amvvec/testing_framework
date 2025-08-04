#pragma once

#include "registry.h"

namespace testing {

// Defines a test case with group, name, and test state
// test_##group##_##name##__##__LINE__ uniquely identifies by line number to
// avoid name clahes
#define TEST(group, name)                                                      \
    static void test_##group##_##name##__##__LINE__(                           \
        testing::TestState& state);                                            \
    static testing::AutoTestRegister auto_##group##_##name##__##__LINE__(      \
        #group, #name, []() {                                                  \
            test_##group##_##name##__##__LINE__(*testing::current_test_state); \
        });                                                                    \
    static void test_##group##_##name##__##__LINE__(testing::TestState* state)

} // namespace testing
