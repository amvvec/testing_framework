#include <unit/mock.h>
#include <unit/unit.h>

using namespace unit::mock;

struct MyFixture {
  int value;
};

void SetUp(MyFixture& fix) { fix.value = 42; }

void TearDown(MyFixture&) {
  // ...
}

TEST_F(MyFixture, ExampleTest) { EXPECT_EQ(fix.value, 42); }

// Recall check

TEST(MockFunctionTest, CallMultipleTimes) {
  unit::mock::MockFunction mock;

  int counter = 0;
  mock.body = [&]() { counter++; };

  mock();
  mock();
  mock();

  ASSERT_CALLS(mock, 3);
  ASSERT_EQ(counter, 3);
}

// Without .body

TEST(MockFunctionTest, NoBodySafeCall) {
  unit::mock::MockFunction mock;

  // Не задаём mock.body
  mock();

  ASSERT_CALLS(mock, 1); // Он должен просто инкрементировать счётчик
}

// Multiple objects

TEST(MockFunctionTest, MultipleMocksIndependent) {
  unit::mock::MockFunction a, b;

  a();
  b();
  b();

  ASSERT_CALLS(a, 1);
  ASSERT_CALLS(b, 2);
}

// is_called() check

TEST(MockFunctionTest, IsCalledFlag) {
  unit::mock::MockFunction mock;

  ASSERT_FALSE(mock.is_called());

  mock();

  ASSERT_TRUE(mock.is_called());
}

// Mock called, but body do nothing

TEST(MockFunctionTest, EmptyBodyDoesNotAffectCount) {
  unit::mock::MockFunction mock;
  mock.body = []() {}; // doing nothing in {}

  mock();
  mock();

  ASSERT_CALLS(mock, 2);
}
