#pragma once

#include "macros.h"
#include "registry.h"

namespace testing {

template <typename Fixture>
inline void setup(Fixture&) {
}

template <typename Fixture>
inline void teardown(Fixture&) {
}

class Fixture {};

} // namespace testing
