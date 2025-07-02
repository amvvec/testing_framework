#pragma once
#ifndef MACROS_H
#define MACROS_H

#include <iostream>

// VERY GOOD IDEA
// ✅ Можешь добавить SFINAE или static_assert (или оставить — GTest тоже не решает это полностью)

// TODO: refactor all macroses
#define FAIL(message) \
    do \
    { \
        std::cerr << "[ FAIL ] " << __FILE__ << ":" << __LINE__ << ": " << message << std::endl; \
        if(unit::current_test_failed) *unit::current_test_failed = true; \
    } while(0)

#define CHECK(condition, message, should_return) \
    do \
    { \
        if(!condition) { \
            FAIL(message); \
            if(return) should_return; \
        } \
    }

#define TEST(group, name) \
    static void test_##group##_##name(); \
    static unit::AutoRegister auto_##group##_##name(#group, #name, &test_##group##_##name); \
    static void test_##group##_##name()

#define TEST_F(fixture, name) \
    static void fixture##_##name##_test(fixture &fix); \
    static void fixture##_##name##_wrapper() \
    { \
        fixture fix; \
        SetUp(fix); \
        fixture##_##name##_test(fix); \
        TearDown(fix); \
    } \
    static unit::AutoRegister auto_##fixture##_##name(#fixture, #name, &fixture##_##name##_wrapper); \
    static void fixture##_##name##_test(fixture &fix)

#define TEST_P(group, name, parameter) \
    void group##_##name##_implementation(parameter); \
    static void group##_##name(parameter &p) \
    { \
        group##_##name##_implementation(p); \
    } \
    void group##_##name##_implementation(parameter p);

// Mock macros
#define EXPECT_CALLS(mock, n) \
    EXPECT_EQ((mock).call(), n)

#define ASSERT_CALLS(mock, n) \
    ASSERT_EQ((mock).call(), n)

#define EXPECT_CALLED(mock) \
    EXPECT_TRUE((mock).is_called())

#define ASSERT_CALLED(mock) \
    ASSERT_TRUE((mock).is_called())

// Standard macros
#define EXPECT_TRUE(condition) CHECK(condition, "EXPECT_TRUE (" #condition ")", false)
#define ASSERT_TRUE(condition) CHECK(condition, "ASSERT_TRUE (" #condition ")", true)

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
#endif // !MACROS_H

// _THROW
