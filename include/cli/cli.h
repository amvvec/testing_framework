#pragma once
#ifndef CLI_H
#define CLI_H

#include <iostream>
#include <string>

namespace unit::cli {

struct CommandOption {
    bool is_help = false;
};

int parse_argument(int argc, char** argv);

int handle_cli(const CommandOption& option);

} // namespace unit::cli

void print_help() {
    std::cout <<

        R"(
    Minimalistic C++ testing framework

    Usage:
        program [option]

    Options:
        --help, -h      Display this help message
    )"

              << std::endl;
}

#endif // !CLI_H
