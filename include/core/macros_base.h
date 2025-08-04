#pragma once

#include "test_state.h"

#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace testing {

class TestOutput {
public:
    // Constuctor with default output to stdout
    explicit TestOutput(std::function<void(std::string)> out =
                            [](std::string message) {
                                std::cout << message;
                            })
        : output_(out) {
    }

    void fail(std::string_view file, int line, std::string_view label,
              std::string_view message) {
        std::string output_message =
            "[ FAIL ] " + std::string(file) + ":" + std::to_string(line) +
            ": " + std::string(label) + std::string(message) + "\n";
        output_(output_message); // Outputs failure message
        if(current_test_state) {
            current_test_state->set_failed();
        }
    }

    template <typename A, typename B>
    void fail_comparison(const A& a, const B& b, std::string_view file,
                         int line, std::string_view label) {
        fail(file, line, label,
             std::string(" Expected: ") + std::to_string(b) +
                 std::string(" Actual: ") + std::to_string(a));
    }

    template <typename A, typename B, typename Op>
    bool compare(const A& a, const B& b, Op op, std::string_view file, int line,
                 std::string_view label) {
        if(!op(a, b)) {
            fail_comparison(a, b, file, line, label);
            return false;
        }
        return true;
    }

    bool check(bool condition, std::string_view file, int line,
               std::string_view label) {
        if(!condition) {
            fail(file, line, label, " Condition was false");
            return false;
        }
        return true;
    }

private:
    std::function<void(std::string)> output_; // Custom output handler
};

// Returns singleton TestOutput instance, initialized by test runner
inline TestOutput& get_output() {
    static TestOutput instance;
    return instance;
}

#define FAIL(message)                                                          \
    testing::get_output().fail(__FILE__, __LINE__, "", message)

#define CHECK(condition, message)                                              \
    do {                                                                       \
        if(!(condition)) {                                                     \
            FAIL(message);                                                     \
        }                                                                      \
    } while(0)

#define COMPARE(a, b, label)                                                   \
    do {                                                                       \
        testing::get_output().compare(a, b, std::equal_to<>(), __FILE__,       \
                                      __LINE__, label);                        \
    } while(0) w

} // namespace testing
