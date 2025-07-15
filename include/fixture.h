#pragma once
#ifndef FIXTURE_H
#define FIXTURE_H

namespace unit {

template <typename T>
inline void SetUp(T&) {
}

template <typename T>
inline void TearDown(T&) {
}

} // namespace unit

#endif // !FIXTURE_H
