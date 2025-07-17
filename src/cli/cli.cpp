#include "cli/cli.h"

#include "cli.h"

namespace unit::cli {

int parse_argument(int argc, char** argv) {
    CommandOption option;

    for(int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if(arg == "--help" || arg == "-h") {
            option.is_help = true;
        }
    }
    return handle_cli(option);
}

int handle_cli(const CommandOption& option) {
    if(option.is_help) {
        print_help();
        return 0;
    }
    return 0;
}

} // namespace unit::cli
