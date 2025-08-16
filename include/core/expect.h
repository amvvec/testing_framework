#pragma once

#include "macros_base.h"
#include "test_output.h"

namespace testing {

#define EXPECT_TRUE(condition)                                                 \
    do {                                                                       \
        if(!(condition)) {                                                     \
            testing::get_output().check_condition(                             \
                (condition), __FILE__, __LINE__,                               \
                "EXPECT_TRUE(" #condition ")");                                \
        }                                                                      \
    } while(0)

#define EXPECT_FALSE(condition)                                                \
    do {                                                                       \
        if((condition)) {                                                      \
            testing::get_output().check_condition(                             \
                (condition), __FILE__, __LINE__,                               \
                "EXPECT_FALSE(" #condition ")");                               \
        }                                                                      \
    } while(0)

#define EXPECT_EQ(a, b)                                                        \
    do {                                                                       \
        testing::get_output().compare((a), (b), std::equal_to<>(), __FILE__,   \
                                      __LINE__, "EXPECT_EQ");                  \
    } while(0)

#define EXPECT_NE(a, b)                                                        \
    do {                                                                       \
        testing::get_output().compare((a), (b), std::not_equal_to<>(),         \
                                      __FILE__, __LINE__, "EXPECT_NE");        \
    } while(0)

} // namespace testing
