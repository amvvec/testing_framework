#pragma once

namespace unit {

class Fixture {
public:
    virtual ~Fixture() = default;

    virtual void setUp() {
    }
    virtual void tearDown() {
    }
};

template <typename T>
class ParametrizedFixture : public Fixture {
public:
    explicit ParametrizedFixture(T param) : parameter_(param) {
    }

    T& get_parameter() {
        return parameter_;
    }

protected:
    T parameter_;
};

template <typename T>
inline void SetUp(T& fix) {
    fix.setUp();
}

template <typename T>
inline void TearDown(T& fix) {
    fix.tearDown();
}

} // namespace unit
