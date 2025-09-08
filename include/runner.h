#pragma once

#include "registry.h"
#include "test_log.h"
#include "test_state.h"

#include <memory>

namespace testing {

struct TestResult {
    std::string group;
    std::string name;
    bool passed;
    std::string error_message;
    long long duration_ms; // Test duration in milliseconds
};

class TestRunner {
private:
    std::unique_ptr<TestState> state_;
    std::vector<TestResult> results_;
    int failure_count_;
    TestLog log_ = get_log();

    TestResult run_test(const TestCase& test);
    void print_summary(size_t total, size_t passed, size_t failed,
                       long long duration_ms) const;

public:
    // Initialize with TestState
    TestRunner();

    int run_all_tests();
};

} // namespace testing
