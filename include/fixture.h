#pragma once

#include "macros.h"
#include "registry.h"

namespace testing {

template <typename T>
inline void setup(T&) {
}

template <typename>
inline void teardown(T&) {
}

class Fixture {};

} // namespace testing
