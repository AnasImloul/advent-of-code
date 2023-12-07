#include <iostream>
#include <vector>
#include "gear_ratios.h"
#include "../../utils.h"

using namespace gearRatios;


void checkForSpecialCharacter(
        int i, int j, bool& marked,
        std::vector<std::string>& lines) {
    if (!utils::isOutOfBounds(i, j, lines.size(), lines[i].size())) {
        marked |= isSpecialChar(lines[i][j]);
    }
}

int solve() {
    int answer = 0;

    std::vector<std::string> lines = utils::readLines();

    int n = (int)lines.size();
    for (int i = 0; i < n; i++) {
        int m = (int)lines[i].size(), j = 0;
        while (j < m) {

            utils::skipUntil(lines[i], j, [](char c){return (bool)isdigit(c);});

            bool marked = false;

            checkForSpecialCharacter(i - 1, j - 1, marked, lines);
            checkForSpecialCharacter(i, j - 1, marked, lines);
            checkForSpecialCharacter(i + 1, j - 1, marked, lines);

            int number = 0;
            while (j < m && isdigit(lines[i][j])) {
                checkForSpecialCharacter(i - 1, j, marked, lines);
                checkForSpecialCharacter(i, j, marked, lines);
                checkForSpecialCharacter(i + 1, j, marked, lines);

                number = number * 10 + (lines[i][j] - '0');
                j++;
            }

            checkForSpecialCharacter(i - 1, j, marked, lines);
            checkForSpecialCharacter(i, j, marked, lines);
            checkForSpecialCharacter(i + 1, j, marked, lines);

            if (marked) answer += number;

        }
    }
    return answer;
}


int gearRatios::firstPart() {
    return utils::solve(solve, input_file);
}

