#pragma once

namespace testing {

class TestState {
private:
    bool failed_;

public:
    TestState() = default;

    void set_failed() {
        failed_ = true;
    }

    void reset_failed() {
        failed_ = false;
    }

    bool is_failed() const {
        return failed_;
    }
};

inline TestState*& get_current_test_state() {
    thread_local TestState* ptr = nullptr;
    return ptr;
}

inline void fail_current_test() {
    if(auto* state = get_current_test_state()) {
        state->set_failed();
    }
}

class TestStateGuard {
public:
    TestStateGuard(TestState* state) {
        get_current_test_state() = state;
    }
    ~TestStateGuard() {
        get_current_test_state() = nullptr;
    }
};

} // namespace testing
