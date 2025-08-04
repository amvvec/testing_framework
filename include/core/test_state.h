#pragma once

namespace testing {

class TestState {
private:
    bool failed_;

public:
    TestState();
    void set_failed();
    bool is_failed() const;
};

// Global test context for macro usage. Initialized by test runner
extern TestState* current_test_state;

inline void set_fail();

} // namespace testing
