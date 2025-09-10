#pragma once

#include "registry.h"

namespace testing {

// Default test macro
#define TEST(group, name)                                                      \
    static void test_##group##_##name();                                       \
    static testing::AutoTestRegister auto_##group##_##name(                    \
        #group, #name, test_##group##_##name);                                 \
    static void test_##group##_##name()

// Test macro for fixtures
#define TEST_F(group, name, par)                                               \
    static void test_##group##__##name##_##par();                              \
    static testing::AutoTestRegister test_##group##__##name##_##par(           \
        #group, #name, #par, test_##group##__##name##_##par);                  \
    static void test_##group##__##name##_##par()

} // namespace testing
