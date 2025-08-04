#include "core/runner.h"

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace testing {

TestRunner::TestRunner() {
    state_ = std::make_unique<TestState>();
    output_ = [](const std::string& message) {
        std::cout << message << std::endl;
    }; // Universal
    failure_count_ = 0;
}

int TestRunner::run_all_tests() {
    auto tests = TestRegistry::get_all_tests();

    int passed = 0, failed = 0;

    for(const auto& test : tests) {
        results_.push_back(run_test(test));
    }

    return failed == 0 ? 0 : 1;
}

TestResult TestRunner::run_test(const TestCase& test) {
    current_test_state = state_.get();

    TestResult result{test.group(), test.name(), false, "", 0};
    output_("[ RUN ] " + test.group() + test.name());

    try {
        test.fn()();
        result.passed = !current_test_state->is_failed();
        if(!result.passed) {
            result.error_message = "Failed";
        }
    } catch(const std::exception& ex) {
        result.passed = false;
        result.error_message = "Exception: " + std::string(ex.what());
    } catch(...) {
        result.passed = false;
        result.error_message = "Uknown exception";
    }

    current_test_state = nullptr;
    return result;
}

// void print_summary(int total, int passed, int failed,
//                long long duration_ms) const {
// output_("\n=== Test Summary ===");
// output_("Total : " + std::to_string(total));
// output_("Passed: " + std::to_string(passed));
// output_("Failed: " + std::to_string(failed));
// output_("Time  : " + std::to_string(duration_ms) + " ms");
// }

} // namespace testing

//         current_test_state = state_.get();
//         for(const auto& test : tests) {
//             results_.push_back(run_test(test));
//             results_.back().passed ? ++passed : ++failed;
//         }
//         current_test_state = nullptr;

//         auto duration =
//         std::chrono::duration_cast<std::chrono::milliseconds>(
//                             std::chrono::steady_clock::now() - start)
//                             .count();
//         failure_count_ = failed;

//         print_summary(tests.size(), passed, failed, duration);
//         return failed == 0 ? 0 : 1;
//     }

//     int run_all_tests(const std::string& filter = "", bool is_list_only =
//     false) {
//         results_.clear();
//         auto tests = filter_tests(TestRegistry::get_all_tests(), filter);

//         if(is_list_only) {
//             print_test_list(tests, filter);
//             return 0;
//         }

//         int passed = 0, failed = 0;
//         auto start = std::chrono::steady_clock::now();

//     TestResult run_test(const TestCase& test) {
//         TestResult result{test.group(), test.name(), false, "", 0};
//         output_("[ RUN ] " + result.group + "." + result.name);

//         auto start = std::chrono::steady_clock::now();
//         try {
//             test.fn()();
//             result.passed = !state_->is_failed();
//             if(!result.passed) {
//                 result.error_message = "Assertion failed";
//             }
//         } catch(const std::exception& ex) {
//             result.passed = false;
//             result.error_message = "Exception: " + std::string(ex.what());
//         } catch(...) {
//             result.passed = false;
//             result.error_message = "Unknown exception";
//         }

//         result.duration_ms =
//             std::chrono::duration_cast<std::chrono::milliseconds>(
//                 std::chrono::steady_clock::now() - start)
//                 .count();
//         output_(result.passed
//                     ? "[ OK ] "
//                     : "[ FAIL ] " + result.group + "." + result.name + " (" +
//                           std::to_string(result.duration_ms) + " ms)" +
//                           (result.passed ? "" : " - " +
//                           result.error_message));
//         return result;
//     }

//     std::vector<TestCase> filter_tests(const std::vector<TestCase>& tests,
//                                        const std::string& filter) const {
//         std::vector<TestCase> result;
//         for(const auto& test : tests) {
//             std::string full_name = test.group() + "." + test.name();
//             if(filter.empty() || full_name.find(filter) != std::string::npos)
//             {
//                 result.push_back(test);
//             }
//         }
//         return result;
//     }

//     void print_test_list(const std::vector<TestCase>& tests,
//                          const std::string& filter) const {
//         output_("[ Listing " + std::to_string(tests.size()) +
//                 " test(s) matching \"" + filter + "\" ]");
//         for(const auto& test : tests) {
//             output_("  " + test.group() + "." + test.name());
//         }
//     }

// } // namespace testing
