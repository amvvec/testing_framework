#pragma once

#include "test_state.h"

#include <functional>
#include <iostream>
#include <sstream>
#include <string>

namespace testing {

class TestOutput {
private:
    /// @brief Low-level message output
    std::function<void(std::string)> output_; // Custom output handler

    void fail(std::string_view file, int line, std::string_view message) {
        std::string msg = std::string(file) + ":" + std::to_string(line) + ": " + std::string(message);
        output_(msg);
        fail_current_test();
    }

public:
    // Constructor with default output to stdout
    explicit TestOutput(std::function<void(std::string)> out =
                            [](std::string message) {
                                std::cout << message << std::endl;
                            })
        : output_(out) {
    }

    void report_failure(std::string_view file, int line, std::string_view label, std::string_view details) {
        std::string msg = std::string(label) + " failed: " + std::string(details);
        fail(file, line, msg);
    }

    template <typename A, typename B, typename OP>
    bool compare(const A& a, const B& b, OP op, std::string_view file, int line, std::string_view label) {
        if(!op(a, b)) {
            report_failure(file, line, label, to_string(a) + " != " + to_string(b));
            return false;
        }
        return true;
    }

    bool check_condition(bool condition, std::string_view file, int line, std::string_view label) {
        if(!condition) {
            report_failure(file, line, label, "Condition was false");
            return false;
        }
        return true;
    }

private:
    // Universal to_string via stream
    template <typename T>
    static std::string to_string(const T& value) {
        if constexpr(std::is_convertible_v<T, std::string>) {
            return std::string(value);
        } else if constexpr(std::is_arithmetic_v<T>) {
            return std::to_string(value);
        } else {
            std::ostringstream oss;
            oss << value; // falback for types with operato<<
            return oss.str();
        }

        // if constexpr(requires { std::to_string(value) }) {
        //     return std::to_string(value);
        // } else {
        //     return std::string(value);
        // }
    }
};

// Returns singleton TestOutput instance, initialized by test runner
inline TestOutput& get_output() {
    static TestOutput instance;
    return instance;
}

} // namespace testing
