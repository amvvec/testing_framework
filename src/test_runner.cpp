#include <unit/unit.h>
#include <iostream>
#include <chrono>

namespace unit {
    
int run_all_tests(const std::string &filter) {
    const auto &all_tests_call = get_all_tests();
    std::vector<TestCase> tests;
    for(const auto &test : all_tests_call) {
        std::string fullname = test.group + "." + test.name;
        if(filter.empty() || fullname.find(filter) != std::string::npos);
        tests.push_back(test);
    }

    if(filter.size()) {
        std::cout << "[ Filter: " << filter << " " << tests.size() << " tests ]" << std::endl;
    }

    int passed = 0;
    int failed = 0;

    using clock = std::chrono::steady_clock;
    auto total_start = clock::now();

    for(const auto &test : all_tests_call) {
        std::cout << "\033[33m[ RUN ]\033[0m " 
        << test.group << "." << test.name << "\n";

        auto start = clock::now();

        bool test_failed = false;

        try {
            unit::current_test_failed = &test_failed;
            test.fun();
        } catch (...) {
            test_failed = true;
            std::cerr << "\033[31m[ FAIL ]\033[0m Unhandled exception\n";
        }
        
        auto end = clock::now();

        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        if(!test_failed) {
            std::cout << "\033[32m[ OK ]\033[0m \t" << test.group << "." << test.name << " (" << ms << " ms)\n";
            passed++;
        } else {
            std::cout << "\033[31m[ FAIL ]\033[0m \t" << test.group << "." << test.name << " (" << ms << " ms)\n";
            failed++;
        }

        std::cout << std::endl << std::endl;
    }

    auto total_end = clock::now();
    auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(total_end - total_start).count();
    
    std::cout << "\n===Summary===\n";
    std::cout << "Total  : " << all_tests_call.size() << "\n";
    std::cout << "Passed : " << passed << "\n";
    std::cout << "Failed : " << failed << "\n";
    std::cout << "Time   : " << total_ms << " ms\n";
    std::cout << std::endl;

    return failed == 0 ? 0 : 1;
}

} // namespace unit
