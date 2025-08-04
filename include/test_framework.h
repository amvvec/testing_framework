#pragma once

#include "core/assert.h"
#include "core/expect.h"
#include "core/macros.h"
#include "core/macros_base.h"
#include "core/registry.h"
#include "core/runner.h"
#include "core/test_state.h"

namespace testing {

// Global setup
inline void initialize() {
    if(!current_test_state) {
        current_test_state = new TestState();
    }
    get_output() = TestOutput([](std::string message) {
        std::cout << message;
    });
}

} // namespace testing
