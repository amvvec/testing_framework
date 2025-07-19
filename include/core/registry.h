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
    TestCase(const std::string& group, const std::string& name,
             std::function<void()> fn);

    const std::string group() const;
    const std::string name() const;
    const std::function<void()>& fun() const;
    void run() const;
};

class AutoTestRegister {
public:
    AutoTestRegister(const std::string& group, const std::string& name,
                     std::function<void()> fn);
};

void register_test(const TestCase& tc);

const std::vector<TestCase>& get_all_tests();

} // namespace testing
