#pragma once
#ifndef REGISTRY_H
#define REGISTRY_H

#include <functional>
#include <string>
#include <vector>

namespace unit {

struct TestCase {
    std::string group;
    std::string name;
    std::function<void()> function_name;
};

struct ParameterTestCase {
    std::string group;
    std::string name;
    std::function<void()> function_name;
    int parameter_list;
};

void register_test(const std::string& group, const std::string& name,
                   std::function<void()> function_name);

const std::vector<TestCase>& get_all_test();

struct AutoTestRegister {
    AutoTestRegister(const std::string group, const std::string& name,
                     std::function<void()> function_name) {
        register_test(group, name, function_name);
    }
};

} // namespace unit

#endif // !REGISTRY_H
