#include "internal/state.h"
#include "registry.h"

#include <chrono>
#include <iostream>

namespace {

std::vector<unit::TestCase>
filter_tests(const std::vector<unit::TestCase>& all_tests,
             const std::string& filter) {
    std::vector<unit::TestCase> filtered;

    for(const auto& test : all_tests) {
        const std::string& full_name = test.group() + "." + test.name();
        if(filtered.empty() || full_name.find(filter) != std::string::npos) {
            filtered.push_back(test);
        }
    }
    return filtered;
}

bool run_test_case(const unit::TestCase& test) {
    using clock = std::chrono::steady_clock;

    std::cout << std::endl
              << "\033[33m[ RUN ]\033[0m " << test.group() << "." << test.name()
              << std::endl;

    auto start = clock::now();
    bool test_failed = false;

    unit::test_fail = &test_failed;

    try {
        test.run();
    } catch(const std::exception& ex) {
        test_failed = true;
        std::cerr << "\033[31m[ FAIL ]\033[0m Exception: " << ex.what() << "\n";
    } catch(...) {
        test_failed = true;
        std::cerr << "\033[31m[ FAIL ]\033[0m Unknown exception\n";
    }

    auto end = clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();
    if(!test_failed) {
        std::cout << "\033[32m[ OK ]\033[0m \t" << test.group() << "."
                  << test.name() << " (" << ms << " ms)\n";
    } else {
        std::cout << "\033[31m[ FAIL ]\033[0m \t" << test.group() << "."
                  << test.name() << " (" << ms << " ms)\n";
    }

    return !test_failed;
}

void print_test_list(const std::vector<unit::TestCase>& tests,
                     const std::string& filter) {
    std::cout << "[ Listing " << tests.size() << " test(s) matching filter \""
              << filter << "\": ]\n";
    for(const auto& test : tests) {
        std::cout << "  " << test.group() << "." << test.name() << "\n";
    }
    std::cout << std::endl;
}

void print_test_summary(size_t total, int passed, int failed,
                        long long total_ms) {
    std::cout << "\n=== Summary ===\n";
    std::cout << "Total  : " << total << "\n";
    std::cout << "Passed : " << passed << "\n";
    std::cout << "Failed : " << failed << "\n";
    std::cout << "Time   : " << total_ms << " ms\n\n";
}

} // anonymous namespace

namespace unit {

int run_all_tests(const std::string& filter, bool is_list_only) {
    const auto& all_tests = get_all_tests();

    auto tests = filter_tests(all_tests, filter);

    if(is_list_only) {
        print_test_list(tests, filter);
        return 0;
    }

    if(!filter.empty()) {
        std::cout << "[ Filter: " << filter << " → " << tests.size()
                  << " test(s) ]\n";
    }

    int passed = 0;
    int failed = 0;

    auto total_start = std::chrono::steady_clock::now();

    for(const auto& test : tests) {
        run_test_case(test) ? ++passed : ++failed;
    }

    auto total_end = std::chrono::steady_clock::now();
    auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                        total_end - total_start)
                        .count();

    print_test_summary(tests.size(), passed, failed, total_ms);

    return failed == 0 ? 0 : 1;
}

} // namespace unit
