#pragma once

#include <vector>
#include "../../utils/utils.h"

namespace gearRatios {
    inline static std::string input_file = "../2023/day_03/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        using SpecialCharacterChecker = void(int, int, bool&, std::vector<std::string>&);
        using Setup = void();
        using Update = void(int, int&);
        using Finalize = void(int&);

        int solve(SpecialCharacterChecker checkForSpecialCharacter, Setup setup, Update update, Finalize finalize) {
            int answer = 0;
            std::vector<std::string> lines = utils::readLines();

            int n = (int)lines.size();
            for (int i = 0; i < n; i++) {
                int m = (int)lines[i].size(), j = 0;
                while (j < m) {

                    utils::skipUntil(lines[i], j, [](char c){return (bool)isdigit(c);});

                    bool marked = false;
                    setup();

                    checkForSpecialCharacter(i - 1, j - 1, marked, lines);
                    checkForSpecialCharacter(i, j - 1, marked, lines);
                    checkForSpecialCharacter(i + 1, j - 1, marked, lines);

                    int number = 0;
                    while (j < m && isdigit(lines[i][j])) {
                        checkForSpecialCharacter(i - 1, j, marked, lines);
                        checkForSpecialCharacter(i + 1, j, marked, lines);

                        number = number * 10 + (lines[i][j] - '0');
                        j++;
                    }

                    checkForSpecialCharacter(i - 1, j, marked, lines);
                    checkForSpecialCharacter(i, j, marked, lines);
                    checkForSpecialCharacter(i + 1, j, marked, lines);

                    if (marked) update(number, answer);
                }
            }
            finalize(answer);
            return answer;
        }

        inline bool isSpecialChar(char c) { return !isdigit(c) && c != '.'; }
    }
}