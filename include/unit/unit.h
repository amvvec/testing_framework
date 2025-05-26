#pragma once

#include <string>
#include <vector>
#include <functional>

#include "macros.h"

namespace unit {
    inline thread_local bool *current_test_failed;

    struct TestCase {
        std::string group;
        std::string name;
        std::function<void()> fun;
    };

    void register_test(const std::string &group, const std::string &name, std::function<void()> fun);

    struct AutoRegister {
        AutoRegister(const std::string group, 
                     const std::string &name, 
                     std::function<void()> fun) {
            register_test(group, name, fun);
        }
    };

    const std::vector<TestCase> &get_all_tests();
    int run_all_tests();
}
