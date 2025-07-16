#include "mock/mock.h"

namespace unit {

void MockFunction::set_body(std::function<void()> fn) {
    body_ = std::move(fn);
}

void MockFunction::operator()() {
    ++count_;
    if(body_) {
        body_();
    }
}

int MockFunction::call_count() const {
    return count_;
}

bool MockFunction::is_called() const {
    return count_ > 0;
}

} // namespace unit
