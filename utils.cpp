//
// Created by user on 05/12/2023.
//

#include "utils.h"

void utils::skipUntil(const std::string &str, int &i, Condition<char> *condition) {
    while (i < str.size() && !condition(str[i])) {
        i++;
    }
}

int utils::nextInt(const std::string& str, int& i) {
    int number = 0;
    while (i < str.size() && isdigit(str[i])) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    return number;
}

std::vector<std::string> utils::readLines() {
    std::vector<std::string> lines;
    while (!std::cin.eof()) {
        std::string line;
        std::getline(std::cin, line);
        lines.push_back(line);
    }
    return lines;
}

inline bool utils::isOutOfBounds(int i, int j, int n, int m) {
    return i < 0 | i >= n | j < 0 | j >= m;
}

template <typename T>
T utils::sum(const std::vector<T>& arr) {
    T answer = 0;
    for (auto& e: arr) answer += e;
    return answer;
}