#pragma once

#include "test_state.h"

#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace testing {

#define FAIL(message)                                                          \
    testing::get_output().report_failure(__FILE__, __LINE__, "", message)

#define CHECK(condition, message)                                              \
    do {                                                                       \
        if(!(condition)) {                                                     \
            FAIL(message);                                                     \
        }                                                                      \
    } while(0)

#define COMPARE(a, b, label)                                                   \
    do {                                                                       \
        testing::get_output().compare(a, b, std::equal_to<>(), __FILE__,       \
                                      __LINE__, label);                        \
    } while(0)

} // namespace testing
