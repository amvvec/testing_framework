#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "macros.h"
#include <string>
#include <vector>
#include <functional>

namespace unit {
inline thread_local bool *current_test_failed;

struct TestCase {
    std::string group;
    std::string name;
    std::function<void()> fun;
};

void register_test(const std::string &group, const std::string &name, std::function<void()> fun);

struct AutoRegister {
    AutoRegister(const std::string group, const std::string &name, std::function<void()> fun) {
        register_test(group, name, fun);
    }
};

const std::vector<TestCase> &get_all_tests();
int run_all_tests(const std::string &filter = "", bool list_only = false);

struct Fixture {
    int value;
};

template<typename T>
inline void SetUp(T&) {}

template<typename T>
inline void TearDown(T&) {}

struct CommandLineOption {
    std::string filter;
    bool list_only = false;
};

CommandLineOption parse_argument(int argc, char **argv);
} // namespace unit
#endif // !UNIT_H
