



#include <fstream>
#include <iostream>
#include <string>
#include "trebuchet.h"
#include "../../utils.h"

using namespace trebuchet;

std::string digits[9] = {
    "one","two", "three",
    "four", "five", "six",
    "seven", "eight", "nine"
};

int longestPrefix(const std::string& line, const std::string& substring, int start) {
    int j = 0;
    while (j < substring.size() && start + j < line.size() && substring[j] == line[start + j]) {
        j++;
    }
    return j;
}

int parse(const std::string& line) {
    std::pair<int, int> left = {-1, INT_MAX}, right = {-1, INT_MIN};

    for (int d = 1; d <= 9; d++) {
        std::string digit = digits[d - 1];
        int i = 0;
        while (i < line.size()) {
            int j = longestPrefix(line, digit, i);
            if (j == digit.size()) {
                if (left.second  > i) left = {d, i};
                if (right.second < i) right = {d, i};
            }
            if (j == 0) i++;
            else i += j;
        }
    }

    int i = 0;
    while (i < line.size()) {
        if (isdigit(line[i])) {
            if (left.second > i) left = {line[i] - '0', i};
            if (right.second < i) right = {line[i] - '0', i};
        }
        i++;
    }
    return left.first * 10 + right.first;
}


int solve() {
    int answer = 0;
    std::string line;
    while (std::cin >> line) {
        answer += parse(line);
    }
    return answer;
}


int trebuchet::secondPart() {
    return utils::solve(solve, input_file);
}