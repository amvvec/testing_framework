#pragma once

#include <functional>
#include <iostream>
#include <string>

namespace testing {

class TestLog {
private:
    std::function<void(const std::string&)> log_output_;

public:
    explicit TestLog(std::function<void(const std::string&)> output =
                         [](const std::string& message) {
                             std::cout << message << std::endl;
                         })
        : log_output_(output) {
    }

    void log(const std::string& message) {
        log_output_(message);
    }

    void log_run(const std::string& group, const std::string& name) {
        log("\033[33m[ RUN ]\033[0m " + group + "." + name);
    }

    void log_success(const std::string& group, const std::string& name,
                     long long duration_ms) {
        log("\033[32m[ OK ]\033[0m " + group + "." + name + " (" +
            std::to_string(duration_ms) + " ms)\n");
    }

    void log_failure(const std::string& group, const std::string& name,
                     const std::string& error_message, long long duration_ms) {
        log("\033[31m[ FAIL ]\033[0m " + group + "." + name + " (" +
            std::to_string(duration_ms) + " ms) - " + error_message + "\n");
    }

    void log_summary(size_t total, size_t pass, size_t fail,
                     long long duration) const {
        log_output_("=== Summary ===");
        log_output_("Total  : " + std::to_string(total));
        log_output_("Passed : " + std::to_string(pass));
        log_output_("Failed : " + std::to_string(fail));
        log_output_("Time   : " + std::to_string(duration) + " ms");
    }

    // void TestRunner::print_summary(size_t total, size_t passed, size_t
    // failed,
    //                                long long duration) const {
    //     output_("=== Summary ===");
    //     output_("Total  : " + std::to_string(total));
    //     output_("Passed : " + std::to_string(passed));
    //     output_("Failed : " + std::to_string(failed));
    //     output_("Time   : " + std::to_string(duration) + " ms");
    // }
};

inline TestLog& get_log() {
    static TestLog instance;
    return instance;
}

} // namespace testing
