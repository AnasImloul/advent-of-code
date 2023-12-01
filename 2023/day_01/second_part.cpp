//
// Created by user on 01/12/2023.
//

#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "trebuchet.h"

std::string digits[18] = {
        "one","two", "three",
        "four", "five", "six",
        "seven", "eight", "nine",
        "1", "2", "3",
        "4", "5", "6",
        "7", "8", "9"
};

namespace {
    bool isNext(const std::string& line, const std::string& substring, int start = 0) {
        int j = 0;
        while (j < substring.size() && start + j < line.size() && substring[j] == line[start + j]) {
            j++;
        }
        return j == substring.size();
    }

    int parse(const std::string& line) {
        int left = -1, right = -1;
        int i = 0;
        while (i < line.size()) {
            for (int d = 0; d < 18; d++) {
                std::string digit = digits[d];
                if (isNext(line, digit, i)) {
                    if (left == -1) left = d % 9 + 1;
                    right = d % 9 + 1;
                    break;
                }
            }
            i++;
        }
        return left * 10 + right;
    }
}

int trebuchet::secondPart() {
    std::streambuf *oldCin = std::cin.rdbuf();
    std::ifstream in("../2023/day_01/in2.txt");
    std::cin.rdbuf(in.rdbuf());
    int answer = trebuchet::solve(parse);
    std::cin.rdbuf(oldCin);



    return answer;
}