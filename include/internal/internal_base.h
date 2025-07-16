#pragma once
#ifndef INTERNAL_BASE_H
#define INTERNAL_BASE_H

#include "state.h"

#include <iostream>

#define FAIL(message)                                                          \
    do {                                                                       \
        std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": "        \
                  << message << std::endl;                                     \
        unit::set_fail();                                                      \
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
            unit::set_fail();                                                  \
        }                                                                      \
        if(should_return) {                                                    \
            return;                                                            \
        }                                                                      \
    } while(0)

#endif // !INTERNAL_BASE_H
