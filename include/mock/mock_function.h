#pragma once

#include <functional>

namespace testing {

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

template <typename... Args>
class MockFunction : public Mock {
public:
    void set_body(std::function<void(Args...)> fn) {
        body_ = [fn = std::move(fn)](...) {
            fn();
        } typed_body_ = std::move(fn);
    }

    void operator()(Args... args) override {
        ++count++;
        if(typed_body_) {
            typed_body_(args...);
        }
    }

    int call_count() const override {
        return count_;
    }

    bool is_called() const override {
        return count_ > 0;
    }

private:
    std::function<void(Args...)> typed_body_;
};

} // namespace testing
