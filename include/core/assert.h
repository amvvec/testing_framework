#pragma once

#include "macros_base.h"
#include "test_output.h"

namespace testing {

#define ASSERT_TRUE(condition)                                                                                         \
    do {                                                                                                               \
        if(!(condition)) {                                                                                             \
            testing::get_output().check_condition((condition), __FILE__, __LINE__, "ASSERT_TRUE(" #condition ")");     \
        }                                                                                                              \
    } while(0)

#define ASSERT_FALSE(condition)                                                                                        \
    do {                                                                                                               \
        if((condition)) {                                                                                              \
            testing::get_output().check_condition((condition), __FILE__, __LINE__, "ASSERT_FALSE(" #condition ")");    \
        }                                                                                                              \
    } while(0)

#define ASSERT_EQ(a, b)                                                                                                \
    do {                                                                                                               \
        testing::get_output().compare((a), (b), std::equal_to<>(), __FILE__, __LINE__, "ASSERT_EQ");                   \
    } while(0)

#define ASSERT_NE(a, b)                                                                                                \
    do {                                                                                                               \
        testing::get_output().compare((a), (b), std::not_equal_to<>(), __FILE__, __LINE__, "ASSERT_NE");               \
    } while(0)

} // namespace testing
