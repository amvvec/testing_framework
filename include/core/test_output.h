#pragma once

#include "test_state.h"

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

namespace testing {

class TestOutput {
private:
    std::function<void(const std::string&)> output_;

    static std::string format_message(std::string_view file, int line,
                                      std::string_view macro,
                                      std::string_view details) {
        return "[ FAIL ] " + std::string(short_base_name(file)) + ":" +
               to_string(line) + " | " + std::string(macro) + " | " +
               std::string(details);
    }

public:
    explicit TestOutput(std::function<void(const std::string&)> output =
                            [](const std::string& message) {
                                std::cout << message;
                            })
        : output_(output) {
    }

    bool check_condition(bool condition, std::string_view file, int line,
                         std::string_view label) {
        if(!condition) {
            std::string message =
                format_message(file, line, label, "Condition was false");
            output_(message + "\n");

            if(get_current_test_state()) {
                get_current_test_state()->set_failed();
            }

            return false;
        }
        return true;
    }

    template <typename A, typename B, typename OP>
    bool compare_values(const A& a, const B& b, OP op, std::string_view file,
                        int line, std::string_view label) {
        if(!op(a, b)) {
            std::string details =
                "Expected: " + to_string(a) + " == " + to_string(b);
            std::string message = format_message(file, line, label, details);
            output_(message + "\n");

            if(get_current_test_state()) {
                get_current_test_state()->set_failed();
            }

            return false;
        }
        return true;
    }

private:
    static inline std::string_view short_base_name(std::string_view file) {
        size_t pos = file.find_last_of("/\\");
        return (pos == std::string_view::npos) ? file : file.substr(pos + 1);
    }

    // to_string overload
    static std::string to_string(const std::string& str) {
        return str;
    }

    static std::string to_string(const char* chr) {
        return std::string(chr);
    }

    template <typename T>
    static std::string to_string(const T& value) {
        if constexpr(std::is_arithmetic_v<T>) {
            return std::to_string(value);
        } else {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }
    }
};

inline TestOutput& get_output() {
    static TestOutput instance;
    return instance;
}

} // namespace testing
