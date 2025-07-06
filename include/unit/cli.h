#pragma once
#ifndef CLI_H
#define CLI_H

#include <string>

namespace unit {

struct CommandLineOption {
    std::string filter;
    bool is_help = false;
    bool is_list = false;
};

CommandLineOption parse_argument(int argc, char** argv);

void show_help();

} // namespace unit

#endif // !CLI_H
