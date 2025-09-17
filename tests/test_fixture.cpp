#include "assert.h" // твои макросы
#include "expect.h"
#include "fixture.h"
#include "macros.h"

#include <iostream>

// фикстура
struct MathFixture : public testing::Test {
    int x;
    void set_up() override {
        x = 42;
    }
    void tear_down() override {
        x = -1;
    }
};

TEST(Math, SimpleAdd) {
    int a = 2, b = 3;
    ASSERT_EQ(a + b, 5); // два аргумента
}

TEST_F(MathFixture, FixtureValue) {
    ASSERT_EQ(x, 42);
}

struct CounterFixture : public testing::Test {
    static inline int counter = 0;
    void set_up() override {
        counter++;
    }
    void tear_down() override {
        counter--;
    }
};

TEST_F(CounterFixture, FirstRun) {
    ASSERT_EQ(counter, 1);
}

TEST_F(CounterFixture, SecondRun) {
    ASSERT_EQ(counter, 1);
}
