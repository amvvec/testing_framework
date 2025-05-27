#include <unit/unit.h>

struct MyFixture {
    int value;
};

void SetUp(MyFixture &fix) {
    fix.value = 42;
}

void TearDown(MyFixture&) {
    // ...
}

TEST_F(MyFixture, ExampleTest) {
    EXPECT_EQ(fix.value, 42);
}
