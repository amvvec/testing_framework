#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "cli.h"
#include "fixture.h"
#include "macros.h"
#include "registry.h"

#include <functional>
#include <string>
#include <vector>

namespace unit {

inline thread_local bool* current_test_fail;

const std::vector<TestCase>& get_all_test();

int run_all_tests(const std::string& filter = "", bool list_only = false);

} // namespace unit
#endif // !UNIT_H
