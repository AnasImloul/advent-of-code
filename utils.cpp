//
// Created by user on 05/12/2023.
//

#include "utils.h"

void utils::skipUntil(const std::string &str, int &i, Condition<char> *condition) {
    while (i < str.size() && !condition(str[i])) {
        i++;
    }
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
