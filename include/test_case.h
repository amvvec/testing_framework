#pragma once
#ifndef TEST_CASE_H
#define TEST_CASE_H

#include <functional>
#include <string>
#include <vector>

namespace unit {

class TestCase {
private:
    std::string group_;
    std::string name_;
    std::function<void()> fn_;

public:
    TestCase(const std::string& group, const std::string& name,
             std::function<void()> fn);

    const std::string group() const;
    const std::string name() const;
    void run() const;
};

class AutoTestRegister {
    AutoTestRegister(const std::string group, const std::string& name,
                     std::function<void()> fn);
};

void register_test(const TestCase& tc);
const std::vector<TestCase>& get_all_tests();

} // namespace unit

#endif // !TEST_CASE_H
