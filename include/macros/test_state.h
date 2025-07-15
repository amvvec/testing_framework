#pragma once
#ifndef TEST_STATE_H
#define TEST_STATE_H

namespace unit {

extern thread_local bool* test_fail;

inline void set_fail() {
    if(test_fail) {
        *test_fail = true;
    }
}

} // namespace unit

#endif // !TEST_STATE_H
