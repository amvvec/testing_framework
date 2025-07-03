#pragma once
#ifndef ASSERT_H
#define ASSERT_H

#include "internal_base.h"

#define ASSERT_TRUE(condition)                                                 \
  CHECK(condition, "ASSERT_TRUE (" #condition ")", true)

#define ASSERT_FALSE(condition)                                                \
  CHECK(!(condition), "ASSERT_TRUE (" #condition ")", true)

#define ASSERT_EQ(a, b) COMPARE(a, b, ==, "ASSERT_EQ", true)

#define ASSERT_NE(a, b) COMPARE(a, b, !=, "ASSERT_NE", true)

#endif // !ASSERT_H
