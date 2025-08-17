#pragma once

#include <functional>
#include <string>
#include <vector>

namespace testing {

class TestCase {
private:
    std::string group_;
    std::string name_;
    std::function<void()> fn_;

public:
    TestCase(const std::string& group, const std::string& name, std::function<void()> fn);

    const std::string& group() const;
    const std::string& name() const;
    const std::function<void()>& fn() const;

    // TODO: Run method
};

class AutoTestRegister {
private:
    TestCase tc_; // Embedded test case instance

public:
    AutoTestRegister(const std::string& group, const std::string& name, std::function<void()> fn);
};

class TestRegistry {
private:
    static std::vector<TestCase> tests_; // Storage for registered tests

public:
    static void register_test(const TestCase& tc);
    static const std::vector<TestCase>& get_all_tests();
};

} // namespace testing
