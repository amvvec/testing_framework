#include "core/registry.h"

namespace testing {

TestCase::TestCase(const std::string& group, const std::string& name,
                   std::function<void()> fn)
    : group_(group), name_(name), fn_(fn) {
}

const std::string& TestCase::group() const {
    return group_;
}
const std::string& TestCase::name() const {
    return name_;
}
const std::function<void()>& TestCase::fn() const {
    return fn_;
}

AutoTestRegister::AutoTestRegister(const std::string& group,
                                   const std::string& name,
                                   std::function<void()> fn)
    : tc_(group, name, fn) {
    TestRegistry::register_test(tc_);
}

void TestRegistry::register_test(const TestCase& tc) {
    tests_.push_back(tc);
}

const std::vector<TestCase>& TestRegistry::get_all_tests() {
    return tests_;
}

std::vector<TestCase> TestRegistry::tests_;

} // namespace testing
