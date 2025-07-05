#pragma once
#ifndef INTERNAL_BASE_H
#define INTERNAL_BASE_H

#include <iostream>

#define FAIL(message)                                                          \
    do {                                                                       \
        std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": "        \
                  << message << std::endl;                                     \
        if(unit::current_test_fail)                                            \
            *unit::current_test_fail = true;                                   \
    } while(0)

#define CHECK(condition, message, should_return)                               \
    do {                                                                       \
        if(!(condition)) {                                                     \
            FAIL(message);                                                     \
            if(should_return)                                                  \
                return;                                                        \
        }                                                                      \
    } while(0)

#define COMPARE(a, b, oper, label, should_return)                              \
    do {                                                                       \
        if(!((a)oper(b))) {                                                    \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": "    \
                      << label "(" #a "," #b ") failed\n"                      \
                      << " Expected:" << (b) << "\n"                           \
                      << "  Actual  : " << (a) << "\n";                        \
            if(unit::current_test_fail) {                                      \
                *unit::current_test_fail = true;                               \
            }                                                                  \
            if(should_return) {                                                \
                return;                                                        \
            }                                                                  \
        }                                                                      \
    } while(0)

#endif // !INTERNAL_BASE_H
