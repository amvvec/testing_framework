#pragma once

namespace testing {

extern thread_local bool test_failed;

inline void set_fail() {
    test_failed = true;
}

} // namespace testing
