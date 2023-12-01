//
// Created by user on 01/12/2023.
//

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include "trebuchet.h"


namespace {
    std::string digits[9] = {
            "one","two", "three",
            "four", "five", "six",
            "seven", "eight", "nine"
    };

    int longestMatch(const std::string& line, const std::string& substring, int start = 0) {
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
                int j = longestMatch(line, digit, i);
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
}

int trebuchet::secondPart() {
    return trebuchet::solve(parse);
}