#pragma once

#include "registry.h"

namespace testing {

#define TEST(group, name)                                                      \
    static void test_##group##_##name();                                       \
    static testing::AutoTestRegister auto_##group##_##name(                    \
        #group, #name, test_##group##_##name);                                 \
    static void test_##group##_##name()

#define TEST_F(fixture, name)                                                  \
    static void fixture##_##name##_test(                                       \
        fixture& fix) static void fixture##_##name##_wrapper();                \
    static testing::AutoTestRegister auto_##fixture##_##name(                  \
        #fixture, #name, &fixture##_##name##_wrapper);                         \
    static void fixture##_##name##_wrapper() {                                 \
        fixture fix;                                                           \
        setup(fix);                                                            \
        fixture##_##name##_test(fix);                                          \
        teardown(fix);                                                         \
    }                                                                          \
    static void fixture##_##name##_test(fixture& fix)

} // namespace testing
