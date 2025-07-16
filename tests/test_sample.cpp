#include "unit.h"

TEST(Test, Test) {
    ASSERT_TRUE(1 == 1);
}

struct MyFixture {
    int value;
};

void SetUp(MyFixture& fix) {
    fix.value = 42;
}

void TearDown(MyFixture&) {
}

TEST_F(MyFixture, ExampleTest) {
    EXPECT_EQ(fix.value, 42);
}

TEST(MockFunctionTest, CallMultipleTimes) {
    unit::MockFunction mock;

    int counter = 0;
    mock.set_body([&]() {
        counter++;
    });

    mock();
    mock();
    mock();

    ASSERT_CALLS(mock, 3);
    ASSERT_EQ(counter, 3);
}

// Without .body

TEST(MockFunctionTest, NoBodySafeCall) {
    unit::MockFunction mock;

    // Не задаём mock.body
    mock();

    ASSERT_CALLS(mock, 1); // Он должен просто инкрементировать счётчик
}

// Multiple objects

TEST(MockFunctionTest, MultipleMocksIndependent) {
    unit::MockFunction a, b;

    a();
    b();
    b();

    ASSERT_CALLS(a, 1);
    ASSERT_CALLS(b, 2);
}

// is_called() check

TEST(MockFunctionTest, IsCalledFlag) {
    unit::MockFunction mock;

    ASSERT_FALSE(mock.is_called());

    mock();

    ASSERT_TRUE(mock.is_called());
}

// Mock called, but body do nothing

TEST(MockFunctionTest, EmptyBodyDoesNotAffectCount) {
    unit::MockFunction mock;
    mock.set_body([]() {
    });

    mock();
    mock();

    ASSERT_CALLS(mock, 2);
}

TEST(FrameworkRegistry, RegisterTest) {
    auto& all = unit::get_all_tests();
    bool found = false;

    for(const auto& a : all) {
        if(a.group() == "FrameworkRegistry" || a.name() == "RegisterTest") {
            found = true;
            break;
        }
    }

    ASSERT_TRUE(found);
}
