#pragma once

#include <vector>
#include "../../utils/utils.h"
#include "../../utils/Advent.h"

namespace gearRatios {
    class GearRatios : public Advent {
    protected:
        GearRatios() : Advent(input_file) {
            lines = utils::readLines(in);
        }

        virtual void checkForSpecialCharacter(int i, int j, bool& marked) = 0;
        virtual void setup() = 0;
        virtual void update(int number, int& answer) = 0;
        virtual void finalize(int& answer) = 0;

        std::string solve() override {
            return std::to_string(solveRatios());
        }

        int solveRatios() {
            int answer = 0;

            int n = (int)lines.size();
            for (int i = 0; i < n; i++) {
                int m = (int)lines[i].size(), j = 0;
                while (j < m) {

                    utils::skipUntil(lines[i], j, [](char c){return (bool)isdigit(c);});

                    bool marked = false;
                    setup();

                    checkForSpecialCharacter(i - 1, j - 1, marked);
                    checkForSpecialCharacter(i, j - 1, marked);
                    checkForSpecialCharacter(i + 1, j - 1, marked);

                    int number = 0;
                    while (j < m && isdigit(lines[i][j])) {
                        checkForSpecialCharacter(i - 1, j, marked);
                        checkForSpecialCharacter(i + 1, j, marked);

                        number = number * 10 + (lines[i][j] - '0');
                        j++;
                    }

                    checkForSpecialCharacter(i - 1, j, marked);
                    checkForSpecialCharacter(i, j, marked);
                    checkForSpecialCharacter(i + 1, j, marked);

                    if (marked) update(number, answer);
                }
            }
            finalize(answer);
            return answer;
        }

        inline static bool isSpecialChar(char c) { return !isdigit(c) && c != '.'; }

        inline static std::string input_file = "../2023/day_03/in.txt";

        std::vector<std::string> lines;
    };
}