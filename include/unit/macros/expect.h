#pragma once
#ifndef EXPECT_H
#define EXPECT_H

#include "internal_base.h"

#define EXPECT_TRUE(condition)                                                 \
  CHECK(condition, "EXPECT_TRUE(" #condition ")", false)

#define EXPECT_FALSE(condition)                                                \
  CHECK(!(condition), "EXPECT_FALSE(", #condition ")", false)

#define EXPECT_EQ(a, b) COMPARE(a, b, !=, "EXPECT_EQ", false)

#define EXPECT_NE(a, b) COMPARE(a, b, !=, "EXPECT_NE", false)

#endif // !EXPECT_H
