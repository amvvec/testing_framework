#include <unit/unit.h>

TEST(debug, checkEXPECT_TRUE) {
    EXPECT_TRUE(false);
}

TEST(MathAdd, HandleNegativeInput) {
    EXPECT_TRUE((-1) + (-10) == 2);
    EXPECT_TRUE((-1) + 6 == 5);
}

// TEST(MathAdd, PositiveInput) {
//     EXPECT_TRUE(1 + 4 == 5);
// }

// TEST(MathAdd, NegativeInput) {
//     EXPECT_TRUE((-1) + (-10) == 2);
//     EXPECT_TRUE((-1) + 6 == 5);
// }

// TEST(MathAdd, RandomInput) {
//     EXPECT_TRUE(-1 + -111 == -2);
// }
