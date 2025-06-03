#include <unit/unit.h>

namespace unit {
    void SetUp(unit::Fixture &fix) {
        fix.value = 10;
    }
    
    void TearDown(unit::Fixture &) {
        // ...
    }
} // namespace unit
