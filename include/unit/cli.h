

#pragma once
#ifndef CLI_H
#define CLI_H

#include <string>

namespace unit {

struct CommandLineOption {
    std::string filter;
    bool list_only = false;
};

CommandLineOption parse_argument(int argc, char** argv);

} // namespace unit

#endif // !CLI_H
