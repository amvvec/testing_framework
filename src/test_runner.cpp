#include <unit/unit.h>
#include <iostream>
#include <chrono>

namespace unit {

inline void report_failure(const char* file, int line, const char* expr, 
                           const std::string& expected, const std::string& actual, 
                           bool is_assert, bool abort = false) {
    std::cerr << "[ FAIL ] " << file << ":" << line << ": " << expr << " failed\n"
              << "  Expected: " << expected << "\n"
              << "  Actual  : " << actual << "\n";
    if (current_test_failed) *current_test_failed = true;
    // if (abort) std::abort(); // или просто return из макроса
}
    
int run_all_tests() {
    const auto &tests = get_all_tests();

    int passed = 0;
    int failed = 0;

    using clock = std::chrono::steady_clock;
    auto total_start = clock::now();

    for(const auto &test : tests) {
        std::cout << "\033[33m[ RUN  ]\033[0m " 
        << test.group << "." << test.name << "\n";

        auto start = clock::now();

        bool test_failed = false;

        try {
            unit::current_test_failed = &test_failed;
            test.fun();
            std::cerr << "[ Debug ] test_failed = " << std::boolalpha << test_failed << "\n";
        } catch (...) {
            test_failed = true;
            std::cerr << "\033[31m[ FAIL ]\033[0m Unhandled exception\n";
        }
        ///////////////////////////
        // std::cout << "  (Debug) test_failed = " << test_failed << "\n"; ////////////

        auto end = clock::now();

        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        if(!test_failed) {
            std::cout << "\033[32m[ OK   ]\033[0m " << test.group << "." << test.name << " (" << ms << " ms)\n";
            passed++;
        } else {
            std::cout << "\033[31m[ FAIL ]\033[0m " << test.group << "." << test.name << " (" << ms << " ms)\n";
            failed++;
        }

        std::cout << "\033[90m[ DONE ]\033[0m " << test.group << "." << test.name << "\n";
    }

    auto total_end = clock::now();
    auto total_ms = std::chrono::duration_cast<std::chrono::milliseconds>(total_end - total_start).count();
    
    std::cout << "\nSummary\n";
    std::cout << "  Total  : " << tests.size() << "\n";
    std::cout << "  Passed : " << passed << "\n";
    std::cout << "  Failed : " << failed << "\n";
    std::cout << "  Time   : " << total_ms << " ms\n";

    return failed == 0 ? 0 : 1;
}

} // namespace unit
