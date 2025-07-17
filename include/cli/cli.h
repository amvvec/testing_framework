#pragma once
#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>

namespace unit::cli {

struct CommandOption {
    bool is_help = false;
    bool is_run = true;
};

int parse_argument(int argc, char** argv);

int handle_cli(const CommandOption& option);

} // namespace unit::cli

#endif // !CLI_H
