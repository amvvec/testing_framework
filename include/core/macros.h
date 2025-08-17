#pragma once

#include "registry.h"

namespace testing {

#define TEST(group, name)                                                                                              \
    static void test_##group##_##name();                                                                               \
    static testing::AutoTestRegister auto_##group##_##name(#group, #name, test_##group##_##name);                      \
    static void test_##group##_##name()

} // namespace testing
