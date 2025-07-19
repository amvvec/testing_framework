#pragma once

#include "core/assert.h"
#include "core/expect.h"

#define EXPECT_CALLS(mock, n) EXPECT_EQ((mock).call_count(), n)
#define ASSERT_CALLS(mock, n) ASSERT_EQ((mock).call_count(), n)
#define EXPECT_CALLED(mock) EXPECT_TRUE((mock).is_called())
#define ASSERT_CALLED(mock) ASSERT_TRUE((mock).is_called())
