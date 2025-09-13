#include "fixture.h"

#include <string>

struct StringFixture : public testing::Fixture {
    std::string s;
};

template <>
inline void testing::setup(StringFixture& f) {
    f.s = "hello world";
}

template <>
inline void testing::teardown(StringFixture& f) {
    f.s.clear();
}

TEST_F(StringFixture, InitHasHello) {
    ASSERT_TRUE(fix.s.find("hello") != std::string::npos);
}

TEST_F(StringFixture, ReplaceWorld) {
    fix.s.replace(fix.s.find("world"), 5, "C++");
    EXPECT_EQ(fix.s, "hello C++");
}

TEST_F(StringFixture, ClearString) {
    fix.s.clear();
    ASSERT_TRUE(fix.s.empty());
}

/**
 *
 */

struct VectorFixture : public testing::Fixture {
    std::vector<int> v;
};

template <>
inline void testing::setup(VectorFixture& f) {
    f.v.assign(10'000'000, 1);
}

template <>
inline void testing::teardown(VectorFixture& f) {
    f.v.clear();
}

TEST_F(VectorFixture, SumIsCorrect) {
    long long sum = std::accumulate(fix.v.begin(), fix.v.end(), 0LL);
    ASSERT_EQ(sum, 10'000'000);
}

TEST_F(VectorFixture, PerformanceAccumulate) {
    auto start = std::chrono::steady_clock::now();
    long long sum = std::accumulate(fix.v.begin(), fix.v.end(), 0LL);
    auto end = std::chrono::steady_clock::now();

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
                  .count();

    std::cout << "[ PERFOM ] VectorFixture Accumulate in " << ms << " ms\n";
    ASSERT_TRUE(ms < 3000);
}

/**
 *
 */

#include <map>

struct MapFixture : public testing::Fixture {
    std::map<int, std::string> m;
};

template <>
inline void testing::setup(MapFixture& f) {
    for(int i = 0; i < 100000; i++) {
        f.m[i] = "val" + std::to_string(i);
    }
}

template <>
inline void testing::teardown(MapFixture& f) {
    f.m.clear();
}

TEST_F(MapFixture, FindMiddle) {
    auto it = fix.m.find(50000);
    ASSERT_TRUE(it != fix.m.end());
    EXPECT_EQ(it->second, "val50000");
}

TEST_F(MapFixture, SizeCheck) {
    ASSERT_EQ(fix.m.size(), 100000u);
}
