#pragma once

#include <iostream>
#include <string>

namespace testing::cli {

struct CommandOption {
    bool is_help = false;
    bool is_run = true;
};

int parse_argument(int argc, char** argv);

int handle_cli(const CommandOption& option);

} // namespace testing::cli
