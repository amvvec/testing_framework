#include "core/registry.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

namespace testing {

static std::vector<TestCase> test_registry;
static std::unordered_set<std::string> registred_name;

TestCase::TestCase(const std::string& group, const std::string& name,
                   std::function<void()> fn)
    : group_(group), name_(name), fn_(fn) {
}

AutoTestRegister::AutoTestRegister(const std::string& group,
                                   const std::string& name,
                                   std::function<void()> fn) {
    register_test(TestCase(group, name, std::move(fn)));
}

void register_test(const TestCase& tc) {
    std::string full_name = tc.group() + "." + tc.name();

    if(tc.group().empty() || tc.name().empty()) {
        std::cerr << "[ WARNING ] Empty test!" << full_name << std::endl;
        return;
    }
    if(!tc.fun()) {
        std::cerr << "[ WARNING ] Null function!" << full_name << std::endl;
        return;
    }
    if(registred_name.count(full_name)) {
        std::cerr << "[ WARNING ] Duplicate test!" << full_name << std::endl;
        return;
    }

    registred_name.insert(full_name);
    test_registry.push_back(tc);
}

const std::vector<TestCase>& get_all_tests() {
    return test_registry;
}

const std::string TestCase::group() const {
    return group_;
}

const std::string TestCase::name() const {
    return name_;
}

const std::function<void()>& TestCase::fun() const {
    return fn_;
}

void TestCase::run() const {
    fn_();
}

} // namespace testing
