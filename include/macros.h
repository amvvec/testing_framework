#pragma once

#include "registry.h"

namespace testing {

#define TEST(group, name)                                                      \
    static void test_##group##_##name();                                       \
    static testing::AutoTestRegister auto_##group##_##name(                    \
        #group, #name, test_##group##_##name);                                 \
    static void test_##group##_##name()

#define TEST_F(fixture, name)                                                  \
    class fixture##_##name##_Test : public fixture {                           \
    public:                                                                    \
        void TestBody();                                                       \
    };                                                                         \
    static void fixture##_##name##_wrapper() {                                 \
        testing::RunFixture<fixture##_##name##_Test>(                          \
            [](fixture##_##name##_Test& t) {                                   \
                t.TestBody();                                                  \
            });                                                                \
    }                                                                          \
    static testing::AutoTestRegister auto_##fixture##_##name(                  \
        #fixture, #name, &fixture##_##name##_wrapper);                         \
    void fixture##_##name##_Test::TestBody()

} // namespace testing
