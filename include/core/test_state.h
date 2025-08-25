#pragma once

namespace testing {

/**
 * @class TestState
 * @brief Tracks the state of a test case.
 *
 * Manages whether a test has failed. Used internally to track assertion
 * failures during test execution. Not thread-safe; use `TestStateGuard` for
 * safe state management.
 */
class TestState {
private:
    bool failed_; ///< Indicates if the test has failed.

public:
    /// @brief Default constructor.
    // Initializes the test state with no failure.
    TestState() : failed_(false) {
    }

    /// @brief Mark the test as failed.
    void set_failed() {
        failed_ = true;
    }

    /// @brief Reset the test failure state.
    void reset_failed() {
        failed_ = false;
    }

    /// @brief Check if the test has failed.
    /// @return `true` if the test has failed, `false` otherwise.
    bool is_failed() const {
        return failed_;
    }
};

/**
 * @brief Get the current test state pointer.
 *
 * Returns a thread-local pointer to the active `TestState`.
 * Used to track the state of the currently executing test.
 *
 * @return Pointer to the current `TestState`, or `nullptr` if none.
 */
inline TestState*& get_current_test_state() {
    thread_local TestState* ptr = nullptr;
    return ptr;
}

/**
 * @brief Mark the current test as failed.
 *
 * Sets the failure state on the current `TestState` if it exists.
 * Thread-safe due to thread-local storage.
 */
inline void fail_current_test() {
    if(auto* state = get_current_test_state()) {
        state->set_failed();
    }
}

/**
 * @class TestStateGuard
 * @brief RAII guard for managing `TestState` lifecycle.
 *
 * Ensures the current `TestState` is set during construction and cleared
 * during destruction, preventing state leaks across tests.
 * Thread-safe when used with thread-local `TestState`.
 */
class TestStateGuard {
public:
    /// @brief Constructor that sets the current test state.
    /// @param state Pointer to the `TestState` to manage.
    TestStateGuard(TestState* state) {
        get_current_test_state() = state;
    }

    /// @brief Destructor that clears the current test state.
    ~TestStateGuard() {
        get_current_test_state() = nullptr;
    }
};

} // namespace testing
