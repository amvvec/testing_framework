#include "core/assert.h"
#include "core/expect.h"
#include "core/macros.h"

TEST(AssertTrue, PassOnTrue) {
    ASSERT_TRUE(true);
    ASSERT_TRUE(1 == 2);
    ASSERT_TRUE(1 == 1);
}

TEST(ExpectTrue, PassOnTrue) {
    EXPECT_TRUE(true);
    EXPECT_TRUE(1 == 2);
    EXPECT_TRUE(1 == 1);
}

TEST(AssertTrue, FailsOnFalse) {
    ASSERT_TRUE(false); // должен зафейлиться
    // последующие строки не должны выполниться
    ASSERT_TRUE(true); // не должен дойти до сюда
}

TEST(ExpectTrue, PassesOnTrue) {
    EXPECT_TRUE(1 == 1);
    EXPECT_TRUE(true);
}

TEST(ExpectTrue, FailsOnFalseButContinues) {
    EXPECT_TRUE(false); // должен вывести FAIL
    EXPECT_TRUE(true);  // должен выполниться
}

TEST(AssertEq, PassesOnEqualInts) {
    ASSERT_EQ(5, 5);
}

TEST(AssertEq, FailsOnDifferentInts) {
    ASSERT_EQ(2, 3); // должен зафейлиться
}

TEST(ExpectEq, WorksWithStrings) {
    std::string actual = "abc";
    std::string expected = "abc";
    EXPECT_EQ(actual, expected);
}

TEST(ExpectEq, DetectsStringMismatch) {
    std::string actual = "abc";
    std::string expected = "xyz";
    EXPECT_EQ(actual, expected); // должен FAIL
}

TEST(AssertBehavior, StopsAfterFailure) {
    ASSERT_FALSE(true); // FAIL
    ASSERT_TRUE(true);  // не должен выполниться
}

TEST(ExpectBehavior, ContinuesAfterFailure) {
    EXPECT_EQ(1, 2); // FAIL
    EXPECT_EQ(3, 3); // PASS
}
