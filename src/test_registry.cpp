#include "unit.h"

static std::vector<unit::TestCase> test_registry;

void unit::register_test(const std::string& group, const std::string& name,
                         std::function<void()> function) {
    test_registry.push_back({group, name, function});
}

const std::vector<unit::TestCase>& unit::get_all_test() {
    return test_registry;
}
