# Custom C++ Testing Framework

Минималистичный учебный фреймворк для юнит-тестов в стиле GoogleTest, написанный с нуля.
Поддерживает регистрацию тестов через макросы, проверки ASSERT_* и EXPECT_*, а также вывод результатов.


---

## Возможности

Регистрация тестов через TEST(group, name)

Проверки:

ASSERT_TRUE, ASSERT_FALSE, ASSERT_EQ, ASSERT_NE

EXPECT_TRUE, EXPECT_FALSE, EXPECT_EQ, EXPECT_NE


### Разделение поведения:

ASSERT_* → останавливает тест после ошибки

EXPECT_* → фиксирует ошибку, но продолжает выполнение

Автоматический сбор и запуск всех тестов

---

## Установка и сборка

Требуется CMake ≥ 3.16 и любой современный компилятор C++17.

git clone https://github.com/username/project.git
cd project
mkdir build && cd build
time cmake ..
time cmake --build .

После сборки:

Библиотека: test_framework

Запуск тестов: ./launch


---

## Пример теста

#include "test_framework.h"

TEST(Math, Addition) {
    ASSERT_EQ(2 + 2, 4);
    EXPECT_TRUE(1 < 2);
}

TEST(Strings, Compare) {
    std::string a = "hello";
    std::string b = "world";
    EXPECT_NE(a, b);
}
