//
// Created by user on 05/12/2023.
//


#pragma once

#include <iostream>
#include <vector>


namespace utils {
    template <typename T>
    using Condition = bool(T);

    // a function to skip indices in a string until a condition is met
    void skipUntil(const std::string& str, int& i, Condition<char> condition);

    std::vector<std::string> readLines();

    bool isOutOfBounds(int i, int j, int n, int m);

    int nextInt(const std::string& str, int& i);

    template <typename T>
    T sum(const std::vector<T>& arr);
}