#include "core/test_state.h"

namespace testing {

TestState::TestState() : failed_(false) {
}

void TestState::set_failed() {
    failed_ = true;
}

bool TestState::is_failed() const {
    return failed_;
}

TestState* current_test_state = nullptr; // Global instance definition

void set_fail() {
    if(current_test_state) {
        current_test_state->set_failed();
    }
}

} // namespace testing
