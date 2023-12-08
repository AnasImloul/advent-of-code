#include <iostream>
#include <fstream>
#include "utils.h"


namespace utils {

    void skipUntil(const std::string &str, int &i, Condition<char> *condition) {
        while (i < str.size() && !condition(str[i])) {
            i++;
        }
    }

    std::string readUntil(const std::string &str, int &i, Condition<char> *condition) {
        int j = i;
        while (i < str.size() && !condition(str[i])) {
            i++;
        }
        return str.substr(j, i - j);
    }

    void skipWhile(const std::string &str, int &i, Condition<char> *condition) {
        while (i < str.size() && condition(str[i])) {
            i++;
        }
    }

    std::string readWhile(const std::string &str, int &i, Condition<char> *condition) {
        int j = i;
        while (i < str.size() && condition(str[i])) {
            i++;
        }
        return str.substr(j, i - j);
    }

    int nextInt(const std::string &str, int &i) {
        int number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return number;
    }

    long long nextLong(const std::string &str, int &i) {
        long long number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return number;
    }

    std::vector<int> parseIntegers(std::string &line) {
        std::vector<int> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c); });
            int number = nextInt(line, i);
            numbers.push_back(number);
        }
        return numbers;
    }

    std::vector<long long> parseLongs(std::string &line) {
        std::vector<long long> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c); });
            long long number = nextLong(line, i);
            numbers.push_back(number);
        }

        return numbers;
    }

    template<typename T>
    void show(std::vector<T> arr) {
        for (T e: arr) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::string> readLines() {
        std::vector<std::string> lines;
        while (!std::cin.eof()) {
            lines.push_back(readLine());
        }
        return lines;
    }

    std::string readLine() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    bool isOutOfBounds(int i, int j, int n, int m) {
        return i < 0 | i >= n | j < 0 | j >= m;
    }

    template<typename T>
    T sum(const std::vector<T> &arr) {
        T answer = 0;
        for (auto &e: arr) answer += e;
        return answer;
    }

    template<typename T>
    T solve(Solver<T> solver, const std::string &input_file) {
        std::streambuf *oldCin = std::cin.rdbuf();
        std::ifstream in(input_file);
        std::cin.rdbuf(in.rdbuf());

        T answer = solver();

        std::cin.rdbuf(oldCin);
        return answer;
    }

    template int sum(const std::vector<int> &arr);
    template ll sum(const std::vector<ll> &arr);

    template void show(std::vector<ll> arr);
    template void show(std::vector<int> arr);
    template void show(std::vector<std::string> arr);

    template int solve<int>(Solver<int> solve, const std::string& input_file);
    template ll solve<ll>(Solver<ll> solve, const std::string& input_file);

}