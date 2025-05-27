#include <unit/unit.h>

// Container for all tests
static std::vector<::unit::TestCase> test_registry;

void ::unit::register_test(const std::string &group, 
                           const std::string &name, 
                           std::function<void()> fun) {
    test_registry.push_back({group, name, fun});
}

const std::vector<::unit::TestCase> &::unit::get_all_tests() {
    return test_registry;
}
