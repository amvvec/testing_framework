#include <string>
#include <unit/unit.h>

namespace unit {

CommandLineOption parse_argument(int argc, char** argv) {
    CommandLineOption option;

    for(int i = 0; i < argc; i++) {
        std::string arg = argv[i];

        if(arg == "--help" || arg == "-h") {
            option.is_help = true;
        } else if(arg == "--list") {
            option.is_list;
        } else if(arg.rfind("--filter=", 0) == 0) {
            option.filter = arg.substr(9);
        }
    }

    return option;
}

void show_help() {
    std::cout <<
        R"(C++ Testing Framework

    Usage:
        launch [option]

    Options:
        -h, --help              Show this help message and exit
            --version           Show framework version (will be soon...)
            --list              List all available tests without running them
            --filter=PATTERN    Run only tests that match the given pattern

    Example:
        launch --list
        launch --filter=MyGroup.TestCase
    )" << std::endl;
}

} // namespace unit
