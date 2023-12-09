#include <iostream>
#include <fstream>
#include <chrono>
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
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        int number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return sign * number;
    }

    long long nextLong(const std::string &str, int &i) {
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        long long number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return sign * number;
    }

    std::vector<int> parseIntegers(std::string &line) {
        std::vector<int> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c) || c == '-' || c == '+'; });
            int number = nextInt(line, i);
            numbers.push_back(number);
        }
        return numbers;
    }

    std::vector<long long> parseLongs(std::string &line) {
        std::vector<long long> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c) || c == '-' || c == '+'; });
            long long number = nextLong(line, i);
            numbers.push_back(number);
        }

        return numbers;
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

    int64_t currentTimeMillis() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }

    int64_t currentTimeMicros() {
        using namespace std::chrono;
        return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }

    int64_t currentTimeNanos() {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }
}