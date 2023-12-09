#pragma once

#include <iostream>
#include <vector>
#include <cstdint>

typedef long long ll;

namespace utils {
    template <typename T>
    using Condition = bool(T);

    static auto isalpha = [](char c) { return (bool) std::isalpha(c); };
    static auto isdigit = [](char c) { return (bool) std::isdigit(c); };
    static auto isspace = [](char c) { return c == ' '; };
    static auto isalnum = [](char c) { return isalpha(c) || isdigit(c); };

    // a function to skip indices in a string until a condition is met
    void skipUntil(const std::string& str, int& i, Condition<char> condition);

    // a function to read indices from a string until a condition is met
    std::string readUntil(const std::string& str, int& i, Condition<char> condition);

    // a function to skip indices in a string while a condition is met
    void skipWhile(const std::string& str, int& i, Condition<char> condition);

    // a function to read indices from a string while a condition is met
    std::string readWhile(const std::string& str, int& i, Condition<char> condition);

    std::vector<std::string> readLines();

    std::string readLine();

    bool isOutOfBounds(int i, int j, int n, int m);

    int nextInt(const std::string& str, int& i);

    std::vector<int> parseIntegers(std::string& line);

    ll nextLong(const std::string& str, int& i);

    std::vector<ll> parseLongs(std::string& line);

    int64_t time();

    template<typename T>
    void show(std::vector<T> arr) {
        for (T e: arr) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    T sum(const std::vector<T> &arr) {
        T answer = 0;
        for (auto &e: arr) answer += e;
        return answer;
    }

    template <class T1, class T2>
    struct hash_pair {
        size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);

            if (hash1 != hash2) return hash1 ^ hash2;
            return hash1;
        }
    };

    template <typename T>
    using Solver = T();

    template<typename T>
    T solve(Solver<T> solver, const std::string &input_file) {
        std::streambuf *oldCin = std::cin.rdbuf();
        std::ifstream in(input_file);
        std::cin.rdbuf(in.rdbuf());

        T answer = solver();

        std::cin.rdbuf(oldCin);
        return answer;
    }

}