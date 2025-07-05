#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "macros.h"
#include "registry.h"

#include <functional>
#include <string>
#include <vector>

namespace unit {
inline thread_local bool* current_test_fail;

const std::vector<TestCase>& get_all_test();

int run_all_tests(const std::string& filter = "", bool list_only = false);

struct Fixture {
    int value;
};

template <typename T>
inline void SetUp(T&) {}

template <typename T>
inline void TearDown(T&) {}

struct CommandLineOption {
    std::string filter;
    bool list_only = false;
};

CommandLineOption parse_argument(int argc, char** argv);
} // namespace unit
#endif // !UNIT_H
