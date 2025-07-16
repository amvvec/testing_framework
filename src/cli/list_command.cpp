#include "cli/list_command.h"

#include "registry.h"

namespace unit::cli {

std::string ListCommand::name() const {
    return "list";
}

std::string ListCommand::description() const {
    return "List all registered tests.";
}

int ListCommand::execute(int argc, char** argv) {
    const auto& tests = get_all_tests();
    for(const auto& t : tests) {
        const std::string& full_name = t.group() + "." + t.name();
        std::cout << " " << full_name << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

} // namespace unit::cli
