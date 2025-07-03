#include <unit/unit.h>

static std::vector<::unit::TestCase> test_registry;

void ::unit::register_test(const std::string& group, const std::string& name,
                           std::function<void()> function_name) {
  test_registry.push_back({group, name, function_name});
}

const std::vector<::unit::TestCase>& ::unit::get_all_tests() {
  return test_registry;
}
