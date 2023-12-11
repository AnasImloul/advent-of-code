#pragma once

#include <vector>
#include "../../utils/utils.h"
#include "../../utils/Advent.h"

namespace mirageMaintenance {
    class MirageMaintenance : public Advent {
    protected:
        MirageMaintenance() : Advent(input_file) {
            for (std::string& line : utils::readLines(in)) {
                lines.emplace_back(utils::parseIntegers(line));
            }
        };

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

        inline static std::string input_file = "../2023/day_09/in.txt";

        std::vector<std::vector<int>> lines;
    };
}