#include <iostream>

namespace macros
{
#define TEST(group, name) \
    static void test_##group##_##name(); \
    static ::unit::AutoRegister auto_##group##_##name(#group, #name, &test_##group##_##name); \
    static void test_##group##_##name()

#define TEST_F(Fixture, TestName) \
    static void Fixture##_##TestName##_test(Fixture &fix); \
    static void Fixture##_##TestName##_wrapper() { \
        Fixture fix; \
        SetUp(fix); \
        Fixture##_##TestName##_test(fix); \
        TearDown(fix); \
    } \
    static ::unit::AutoRegister auto_##Fixture##_##TestName(#Fixture, #TestName, &Fixture##_##TestName##_wrapper); \
    static void Fixture##_##TestName##_test(Fixture &fix)
    
#define EXPECT_EQ(val1, val2) \
    do \
    { \
        if ((val1) != (val2)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": EXPECT_EQ(" #val1 ", " #val2 ") failed\n" \
                      << "  Expected: " << (val2) << "\n" \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while (0)

#define ASSERT_EQ(val1, val2) \
    do \
    { \
        if ((val1) != (val2)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": ASSERT_EQ(" #val1 ", " #val2 ") failed\n" \
                      << "  Expected: " << (val2) << "\n" \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
            return; \
        } \
    } while (0)

#define EXPECT_TRUE(condition) \
    do \
    { \
        if (!(condition)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": EXPECT_TRUE(" #condition ") failed\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while (0)

#define ASSERT_TRUE(condition) \
    do \
    { \
        if (!(condition)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": ASSERT_TRUE(" #condition ") failed\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
            return; \
        } \
    } while (0)

#define EXPECT_NE(val1, val2) \
    do \
    { \
        if((val1) == (val2)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": EXPECT_NE(" #val1 ", " #val2 ") failed\n" \
                      << "  Expected: " << (val2) << "\n" \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while(0)

#define ASSERT_NE(val1, val2) \
    do \
    { \
        if((val1) == (val2)) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": ASSERT_NE(" #val1 ", " #val2 ") failed\n" \
                      << "  Expected: " << (val2) << "\n" \
                      << "  Actual  : " << (val1) << "\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
            return; \
        } \
    } while(0)

#define EXPECT_FALSE(condition) \
    do \
    { \
        if(condition) { \
            std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                      << ": EXPECT_FALSE(" #condition ") failed\n"; \
            if (unit::current_test_failed) *unit::current_test_failed = true; \
        } \
    } while(0)

#define ASSERT_FALSE(condition) \
    do \
    { \
        if(condition) { \
                std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ \
                          << ": ASSERT_FALSE(" #condition ") failed\n"; \
                if (unit::current_test_failed) *unit::current_test_failed = true; \
                return; \
        } \
    } while(0)
} // macros
