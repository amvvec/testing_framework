#pragma once
#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#define TEST(group, name)                                                      \
  static void test_##group##_##name();                                         \
  static unit::AutoRegister auto_##group##_##name(#group, #name,               \
                                                  &test_##group##_##name);     \
  static void test_##group##_##name()

#define TEST_F(fixture, name)                                                  \
  static void fixture##_##name##_test(fixture& fix);                           \
  static void fixture##_##name##_wrapper() {                                   \
    fixture fix;                                                               \
    SetUp(fix);                                                                \
    fixture##_##name##_test(fix);                                              \
    TearDown(fix);                                                             \
  }                                                                            \
  static unit::AutoRegister auto_##fixture##_##name(                           \
      #fixture, #name, &fixture##_##name##_wrapper);                           \
  static void fixture##_##name##_test(fixture& fix);

#define TEST_P(group, name, parameter)                                         \
  void group##_##name##_implementation(parameter);                             \
  static void group##_##name(parameter& p) {                                   \
    group##_##name##_implementation(p);                                        \
  }                                                                            \
  void group##_##name##_implementation(parameter p);

#endif // !TEST_MACROS_H
