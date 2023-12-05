//
// Created by user on 03/12/2023.
//


#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "gear_ratios.h"
#include "../../utils.h"


using namespace gearRatios;


void checkForSpecialCharacter(
        int i, int j, bool& marked,
        std::vector<std::string>& lines,
        std::vector<std::pair<int, int>>& currentGears
        ) {
    if (!utils::isOutOfBounds(i ,j, lines.size(), lines[i].size())) {
        marked |= isSpecialChar(lines[i][j]);
        if (lines[i][j] == '*') currentGears.push_back({i, j});
    }
}

int solver() {
    int answer = 0;
    std::vector<std::string> lines = utils::readLines();
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, utils::hash_pair<int, int>> gears;

    int n = lines.size();
    for (int i = 0; i < n; i++) {
        int m = lines[i].size(), j = 0;
        while (j < m) {

            utils::skipUntil(lines[i], j, [](char c){return (bool)isdigit(c);});

            bool marked = false;
            std::vector<std::pair<int, int>> currentGears;

            checkForSpecialCharacter(i - 1, j - 1, marked, lines, currentGears);
            checkForSpecialCharacter(i, j - 1, marked, lines, currentGears);
            checkForSpecialCharacter(i + 1, j - 1, marked, lines, currentGears);

            int number = 0;
            while (j < m && isdigit(lines[i][j])) {
                checkForSpecialCharacter(i - 1, j, marked, lines, currentGears);
                checkForSpecialCharacter(i, j, marked, lines, currentGears);
                checkForSpecialCharacter(i + 1, j, marked, lines, currentGears);

                number = number * 10 + (lines[i][j] - '0');
                j++;
            }

            checkForSpecialCharacter(i - 1, j, marked, lines, currentGears);
            checkForSpecialCharacter(i, j, marked, lines, currentGears);
            checkForSpecialCharacter(i + 1, j, marked, lines, currentGears);

            if (!marked) continue;

            for (auto gear: currentGears) {
                if (gears.find(gear) == gears.end()) {
                    gears[gear] = {number, -1};
                } else {
                    if (gears[gear].second == -1) gears[gear].second = number;
                    else gears[gear].first = -1;
                }
            }
        }
    }

    for (auto gear: gears) {
        if (gear.second.first != -1 && gear.second.second != -1) {
            answer += gear.second.first * gear.second.second;
        }
    }

    return answer;
}


int gearRatios::secondPart() {
    return gearRatios::solve(solver);
}


