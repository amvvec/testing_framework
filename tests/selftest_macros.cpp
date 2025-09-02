#include "core/assert.h"
#include "core/expect.h"
#include "core/macros.h"

#include <chrono>
#include <map>
#include <numeric>
#include <string>
#include <vector>

TEST(Performance, MillionAssertions) {
    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < 1'000'000; ++i) {
        EXPECT_TRUE(i >= 0);
    }

    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();

    std::cout << "[ PERFOM ] MillionAssertions completed in " << ms << " ms\n";

    ASSERT_TRUE(ms < 2000);
}

TEST(Performance, BillionAssertions) {
    auto start = std::chrono::steady_clock::now();

    for(int i = 0; i < 1'000'000'000; ++i) {
        EXPECT_TRUE(i >= 0);
    }

    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();

    std::cout << "[ PERFOM ] BillionAssertions completed in " << ms << " ms\n";

    ASSERT_TRUE(ms < 5000);
}

TEST(Performance, VectorSum) {
    std::vector<int> v(10'000'000, 1);

    auto start = std::chrono::steady_clock::now();
    long long sum = std::accumulate(v.begin(), v.end(), 0LL);
    auto end = std::chrono::steady_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();

    std::cout << "[ PERFOM ] VectorSum completed in " << ms
              << " ms (sum=" << sum << ")\n";

    ASSERT_EQ(sum, 10'000'000);
    ASSERT_TRUE(ms < 3000);
}

TEST(Stress, LargeLoop) {
    long long sum = 0;
    for(int i = 0; i < 1'000'000; i++) {
        sum += i;
    }
    ASSERT_TRUE(sum > 0); // sanity check
}

TEST(StressSpaces, LeadingSpaces) {
    std::string s = "   hello";
    ASSERT_EQ(s.find("hello"), 3u);
}

TEST(StressSpaces, TrailingSpaces) {
    std::string s = "world   ";
    EXPECT_EQ(s.substr(0, 5), "world");
}

TEST(StressSpaces, MultipleSpacesInside) {
    std::string s = "a   b";
    EXPECT_TRUE(s.find("   ") != std::string::npos);
}

TEST(StressSpaces, EmptyString) {
    std::string s = "";
    ASSERT_TRUE(s.empty());
}

TEST(StressSpaces, OnlySpaces) {
    std::string s = "     ";
    EXPECT_EQ(s.size(), 5u);
}

TEST(StressSpaces, TabsInside) {
    std::string s = "a\tb";
    EXPECT_TRUE(s.find('\t') != std::string::npos);
}

TEST(StressSpaces, MixedSpacesAndTabs) {
    std::string s = " \t \t ";
    ASSERT_EQ(s.size(), 5u);
}

TEST(StressSpaces, Newlines) {
    std::string s = "line1\nline2";
    EXPECT_TRUE(s.find('\n') != std::string::npos);
}

TEST(StressSpaces, CarriageReturn) {
    std::string s = "line1\rline2";
    EXPECT_TRUE(s.find('\r') != std::string::npos);
}

TEST(StressSpaces, ComplexWhitespace) {
    std::string s = " \t\n\r mix ";
    ASSERT_TRUE(!s.empty());
}

TEST(AssertTrue, BasicPass) {
    ASSERT_TRUE(1 + 1 == 2);
}

TEST(AssertFalse, Works) {
    ASSERT_FALSE(5 < 3);
}

TEST(AssertEq, IntComparison) {
    int a = 42;
    int b = 42;
    ASSERT_EQ(a, b);
}

TEST(AssertNe, DoubleComparison) {
    double x = 3.14159;
    double y = 2.71828;
    ASSERT_NE(x, y);
}

TEST(ExpectEq, StringComparison) {
    std::string s1 = "hello";
    std::string s2 = "hello";
    EXPECT_EQ(s1, s2);
}

TEST(ExpectNe, CStringComparison) {
    const char* a = "abc";
    const char* b = "xyz";
    EXPECT_NE(std::string(a),
              std::string(b)); // string for safety
}

TEST(ExpectTrue, PointerNull) {
    int* ptr = nullptr;
    EXPECT_TRUE(ptr == nullptr);
}

TEST(ExpectFalse, BoolExpression) {
    EXPECT_FALSE(false && true);
}
