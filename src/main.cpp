#include <unit/unit.h>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::string filter;

    for(int i = 0; i < argc; i++) {
        std::string arg = argv[i];
        const std::string prefix = "--filter=";
        if(arg.find(prefix) == 0) {
            filter = arg.substr(prefix.size());
        }
    }

    std::cout << std::endl;
    return ::unit::run_all_tests(filter);
}
