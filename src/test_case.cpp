#include "test_case.h"

#include <vector>

namespace unit {

static std::vector<TestCase> test_registry;

TestCase::TestCase(const std::string& group, const std::string& name,
                   std::function<void()> fn)
    : group_(group), name_(name), fn_(fn) {
}

void register_test(const TestCase& tc) {
    test_registry.push_back(tc);
}

const std::vector<TestCase>& get_all_tests() {
    return test_registry;
}

AutoTestRegister::AutoTestRegister(const std::string group,
                                   const std::string& name,
                                   std::function<void()> fn) {
    register_test(TestCase(group, name, std::move(fn)));
}

const std::string TestCase::group() const {
    return group_;
}

const std::string TestCase::name() const {
    return name_;
}

void TestCase::run() const {
    fn_();
}

} // namespace unit
