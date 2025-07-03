#pragma once
#ifndef MOCK_MACROS_H
#define MOCK_MACROS_H

#include "assert.h"
#include "expect.h"

#define EXPECT_CALLS(mock, n) EXPECT_EQ((mock).call(), n)
#define ASSERT_CALLS(mock, n) ASSERT_EQ((mock).call(), n)
#define EXPECT_CALLED(mock) EXPECT_TRUE((mock).is_called())
#define ASSERT_CALLED(mock) ASSERT_TRUE((mock).is_called())

#endif // !MOCK_MACROS_H
