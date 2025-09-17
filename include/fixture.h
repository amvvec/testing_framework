#pragma once

namespace testing {

class Test {
public:
    virtual ~Test() = default;

    virtual void set_up() {
    }
    virtual void tear_down() {
    }
};

template <typename Test, typename TestFunc>
void RunFixture(TestFunc&& func) {
    Test fix;
    fix.set_up();
    func(fix);
    fix.tear_down();
}

} // namespace testing
