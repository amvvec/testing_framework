#pragma once
#ifndef MOCK_H
#define MOCK_H

#include <functional>

namespace unit {

class IMock {
protected:
    int count_ = 0;
    std::function<void()> body_;

public:
    virtual ~IMock() = default;

    virtual void set_body(std::function<void()> fn) = 0;
    virtual void operator()() = 0;
    virtual int call_count() const = 0;
    virtual bool is_called() const = 0;
};

class MockFunction : public IMock {
public:
    void set_body(std::function<void()> fn) override;
    void operator()() override;
    int call_count() const override;
    bool is_called() const override;
};

} // namespace unit

#endif // !MOCK_H
