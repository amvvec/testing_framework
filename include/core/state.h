#pragma once

namespace unit {

extern thread_local bool* test_fail;

inline void set_fail() {
    if(test_fail) {
        *test_fail = true;
    }
}

} // namespace unit
