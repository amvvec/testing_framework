#include "core/runner.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace testing {

TestRunner::TestRunner() {
    failure_count_ = 0;
    state_ = std::make_unique<TestState>();
    output_ = [](const std::string& message) { // Universal output
        std::cout << message << std::endl;
    };
}

int TestRunner::run_all_tests() {
    std::cout << std::endl;

    results_.clear();
    auto tests = TestRegistry::get_all_tests();

    size_t passed = 0, failed = 0;

    auto total_start = std::chrono::steady_clock::now();

    for(const auto& test : tests) {
        // Skip empty or duplicate tests
        if(!test.fn() || std::find_if(results_.begin(), results_.end(),
                                      [&test](const TestResult& r) {
                                          return r.group == test.group() &&
                                                 r.name == test.name();
                                      }) != results_.end()) {
            continue;
        }

        results_.push_back(run_test(test));
        results_.back().passed ? passed++ : failed++;
    }

    auto total_end = std::chrono::steady_clock::now();
    auto total_duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                              total_end - total_start)
                              .count(); // Duration of all tests

    failure_count_ = failed;

    print_summary(tests.size(), passed, failed, total_duration);

    std::cout << std::endl;
    return failed == 0 ? 0 : 1;
}

TestResult TestRunner::run_test(const TestCase& test) {
    TestResult result{test.group(), test.name(), false, "", 0};
    output_("\033[33m[ RUN ]\033[0m " + test.group() + "." + test.name());

    auto start = std::chrono::steady_clock::now();

    auto local_state = std::make_unique<TestState>();
    get_current_test_state() = local_state.get();
    local_state->reset_failed();

    // fail_current_test();

    try {
        test.fn()();
        result.passed = !get_current_test_state()->is_failed();
        if(!result.passed) {
            result.error_message = "Assertion failed";
        }
    } catch(std::exception& ex) {
        result.passed = false;
        result.error_message = "Execption: " + std::string(ex.what());
    } catch(...) {
        result.passed = false;
        result.error_message = "Uknown exception";
    }

    auto end = std::chrono::steady_clock::now();
    result.duration_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count();

    output_(result.passed
                ? "\033[32m[ OK ]\033[0m " + test.group() + "." + test.name() +
                      " (" + std::to_string(result.duration_ms) + " ms)" + "\n"

                : "\033[31m[ FAIL ]\033[0m " + test.group() + "." +
                      test.name() + " (" + std::to_string(result.duration_ms) +
                      " ms) - " + result.error_message + "\n");

    get_current_test_state() = nullptr;

    return result;
}

void TestRunner::print_summary(size_t total, size_t passed, size_t failed,
                               long long duration) const {
    output_("=== Summary ===");
    output_("Total  : " + std::to_string(total));
    output_("Passed : " + std::to_string(passed));
    output_("Failed : " + std::to_string(failed));
    output_("Time   : " + std::to_string(duration) + " ms");
}

}; // namespace testing
