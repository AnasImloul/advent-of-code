//
// Created by user on 05/12/2023.
//


#pragma once

#include <iostream>
#include <vector>

typedef long long ll;

namespace utils {
    template <typename T>
    using Condition = bool(T);

    // a function to skip indices in a string until a condition is met
    void skipUntil(const std::string& str, int& i, Condition<char> condition);

    std::vector<std::string> readLines();

    bool isOutOfBounds(int i, int j, int n, int m);

    int nextInt(const std::string& str, int& i);

    std::vector<int> parseIntegers(std::string& line);

    ll nextLong(const std::string& str, int& i);

    std::vector<ll> parseLongs(std::string& line);

    template <typename T>
    void show(std::vector<T> arr);

    template <typename T>
    T sum(const std::vector<T>& arr);

    template <class T1, class T2>
    struct hash_pair {
        size_t operator()(const std::pair<T1, T2>& p) const;
    };

    template <typename T>
    using Solver = T();

    template <typename T>
    T solve(Solver<T> solver,const std::string& input_file);
}