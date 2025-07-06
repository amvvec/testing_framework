#pragma once
#ifndef UNIT_H
#define UNIT_H

#include "cli.h"
#include "fixture.h"
#include "macros.h"
#include "registry.h"
#include "runner.h"

// #include <functional>
// #include <string>
// #include <vector>

namespace unit {

inline thread_local bool* current_test_fail;

const std::vector<TestCase>& get_all_test();

} // namespace unit

#endif // !UNIT_H
