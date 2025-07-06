#include <iostream>
#include <unit/unit.h>

int main(int argc, char** argv) {

    auto option = unit::parse_argument(argc, argv);

    if(option.is_help) {
        unit::show_help();
    }

    std::cout << std::endl;
    return ::unit::run_all_tests(option.filter, option.is_list);
}
