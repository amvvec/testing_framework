#pragma once

#include "test_output.h"

namespace testing {

#define ASSERT_TRUE(condition)                                                 \
    do {                                                                       \
        if(!(condition)) {                                                     \
            testing::get_output().check_condition(                             \
                (condition), __FILE__, __LINE__,                               \
                "ASSERT_TRUE(" #condition ")");                                \
            return;                                                            \
        }                                                                      \
    } while(0)

#define ASSERT_FALSE(condition)                                                \
    do {                                                                       \
        if((condition)) {                                                      \
            testing::get_output().check_condition(                             \
                (condition), __FILE__, __LINE__,                               \
                "ASSERT_FALSE(" #condition ")");                               \
            return;                                                            \
        }                                                                      \
    } while(0)

#define ASSERT_EQ(a, b)                                                        \
    do {                                                                       \
        if(!testing::get_output().compare_values((a), (b), std::equal_to<>(),  \
                                                 __FILE__, __LINE__,           \
                                                 "ASSERT_EQ")) {               \
            return;                                                            \
        }                                                                      \
    } while(0)

#define ASSERT_NE(a, b)                                                        \
    do {                                                                       \
        if(!testing::get_output().compare_values(                              \
               (a), (b), std::not_equal_to<>(), __FILE__, __LINE__,            \
               "ASSERT_NE")) {                                                 \
            return;                                                            \
        }                                                                      \
    } while(0)

} // namespace testing
