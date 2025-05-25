#include <iostream>

#define TEST(group, name) \
    static void test_##group##_##name(); \
    static unit::AutoRegister auto_##group##_##name(#group, #name, &test_##group##_##name); \
    static void test_##group##_##name()

#define EXPECT_EQ(val1, val2) \
    do { \
        if(!((val1) == (val2))) { \
            std::cerr << "  Expected: " << (val2) << "\n" \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while(0)

#define ASSERT_EQ(val1, val2) \
    do { \
        if(!((val1) == (val2))) { \
            std::cerr << "[ FAIL ]" << __FILE__ << __LINE__ \
                      << ": EXPECT_EQ(" #val1 ", " #val2") failed" \
                      << "  Expected: " << (val2) \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
            return; \
        } \
    } while(0)

#define EXPECT_TRUE(condition) \
    do { \
        std::cout << "Evaluating condition: " #condition << " → " << ((condition) ? "true" : "false") << "\n"; \
        if (!(condition)) { \
            std::cout << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": EXPECT_TRUE(" #condition ") failed\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while (0)

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": ASSERT_TRUE(" #condition ") failed\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
            return; \
        } \
    } while (0)
