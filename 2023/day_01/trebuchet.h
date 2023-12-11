#pragma once

#include <vector>
#include "../../utils/utils.h"

namespace trebuchet {
    inline static std::string input_file = "../2023/day_01/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        using DigitChecker = int(const std::string&, int);

        int calculateScore(std::string& line, DigitChecker digitChecker){
            int left = -1, right = -1;
            for (int i = 0; i < line.size(); i++) {
                int digit = digitChecker(line, i);
                if (digit != -1) {
                    if (left == -1) left = digit;
                    right = digit;
                }
            }
            return left * 10 + right;
        }

        int solve(DigitChecker digitChecker) {
            int answer = 0;
            for (std::string& line : utils::readLines()) {
                answer += calculateScore(line, digitChecker);
            }
            return answer;
        }
    }
}