/**
 * @file main.cc
 * @author Stanislav Lebedev (kugui@yandex.ru)
 * @brief
 *   Validate std::optional behaviour during compare with different types and values.
 *
 * @version 0.1
 * @date 2021-10-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <optional>
#include <string_view>

template <typename T>
std::optional<T> get(std::string_view key) {
    if (key == "key_1") {
        return std::optional<T>{1l};
    }
    if (key == "key_2") {
        return std::optional<T>{2l};
    }
    return {};
}

int main(const int, const char **) {
    auto const val_correct_1 = get<long>("key_1");
    auto const val_correct_2 = get<float>("key_2");
    auto const val_wrong = get<long>("test");

    auto const want_1 = std::optional<int>(1l);
    auto const want_2 = std::optional<int>(2l);

    std::cout << "(val_correct_1 == want_1) => " << (val_correct_1 == want_1) << std::endl;
    std::cout << "(val_correct_2 == want_1) => " << (val_correct_2 == want_1) << std::endl;
    std::cout << "(val_correct_2 == want_2) => " << (val_correct_2 == want_2) << std::endl;
    std::cout << "(val_wrong == want_1) => " << (val_wrong == want_1) << std::endl;
    return 0;
}
