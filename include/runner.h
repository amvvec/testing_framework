#pragma once
#ifndef RUNNER_H
#define RUNNER_H

#include <string>

namespace unit {

int run_all_tests(const std::string& filter = "", bool is_list_only = false);

} // namespace unit

#endif // !RUNNER_H
