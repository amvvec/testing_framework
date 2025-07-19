#pragma once

#include "test_state.h"

#include <iostream>
#include <string>

namespace testing {

inline void report_failure(const char* file, int line,
                           const std::string& message) {
    std::cerr << "[ FAIL ] " << file << "." << line << ": " << message
              << std::endl;
    set_fail();
}

template <typename T, typename U>
inline void report_comparison_failure(const char* file, int line,
                                      const T& actual, const U& expected,
                                      const char* operation,
                                      const char* label) {
    std::cerr << "[ FAIL ] " << file << ":" << line << ": " << label << "("
              << actual << "," << expected << ") failed\n"
              << " Expected: " << expected << "\n"
              << " Actual : " << actual << "\n";
    set_fail();
}

#define CHECK(condition, message, should_return)                               \
    do {                                                                       \
        if(!(condition)) {                                                     \
            testing::report_failure(__FILE__, __LINE__, message);              \
            if(should_return) {                                                \
                return;                                                        \
            }                                                                  \
        }                                                                      \
    } while(0)

#define COMPARE(a, b, operation, label, should_return)                         \
    do {                                                                       \
        if(!(a)operation(b)) {                                                 \
            testing::report_comparison_failure(__FILE__, __LINE__, (a), (b),   \
                                               #operation, #label);            \
            if(should_return) {                                                \
                return;                                                        \
            }                                                                  \
        }                                                                      \
    } while(0)

} // namespace testing
