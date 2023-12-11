#pragma once

#include <vector>
#include "../../utils/utils.h"

namespace mirageMaintenance {
    inline static std::string input_file = "../2023/day_09/in.txt";

    int firstPart();
    int secondPart();

    namespace {
        std::vector<std::vector<int>> readInput() {
            std::vector<std::vector<int>> input;
            for (std::string& line : utils::readLines()) {
                input.emplace_back(utils::parseIntegers(line));
            }
            return input;
        }

        int extrapolate(std::vector<int>& line, int n) {
            if (n == 1) {
                return line[0];
            }

            // apply the difference
            bool zero = true;
            for (int i = 0; i < n - 1; i++) {
                line[i] = line[i + 1] - line[i];
                if (line[i]) zero = false;
            }

            int answer;

            if (zero) answer = line[n - 1];
            else answer = extrapolate(line, n - 1) + line[n - 1];

            // revert the difference
            for (int i = n - 2; i >= 0; i--) {
                line[i + 1] = line[i + 1] + line[i];
            }

            return answer;
        }
    }
}