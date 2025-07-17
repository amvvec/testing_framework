#include "cli/cli.h"

#include "unit.h"

namespace unit::cli {

void print_help() {
    std::cout <<
        R"(
Minimalistic C++ testing framework

Usage:
    program [option]

Options:
    --help, -h      Display this help message
)" << std::endl;
}

int parse_argument(int argc, char** argv) {
    CommandOption option;

    for(int i = 1; i < argc; ++i) {
        if(!argv[i] || *argv[i] == '\0') {
            std::cerr << "Error: Empty argument at position" << i << std::endl;
            return 1;
        }

        std::string arg = argv[i];
        if(arg == "--help" || arg == "-h") {
            option.is_help = true;
            option.is_run = false;
        } else {
            std::cerr << "Error: Unknown argument '" << arg << "'" << std::endl;
            return 1;
        }
    }
    return handle_cli(option);
}

int handle_cli(const CommandOption& option) {
    if(option.is_help) {
        print_help();
        return 0;
    }

    if(option.is_run) {
        return unit::run_all_tests();
    }

    return 0;
}

} // namespace unit::cli
