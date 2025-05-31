#include <unit/unit.h>
#include <string>

namespace unit
{
CommandLineOption parse_argument(int argc, char **argv) {
    CommandLineOption option;
    for(int i = 0; i < argc; i++) {
        std::string arg = argv[i];
        if(arg.rfind("--filter=", 0) == 0) {
            option.filter = arg.substr(9);
        }
        else if(arg == "--list") {
            option.list_only = true;
        }
    }
    return option;
}
}
