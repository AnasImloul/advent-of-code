#include <iostream>
#include <vector>
#include <unordered_map>
#include "gear_ratios.h"

using namespace gearRatios;

static std::vector<std::pair<int, int>> currentGears;
static std::unordered_map<std::pair<int, int>, std::pair<int, int>, utils::hash_pair<int, int>> gears;

void checkForSpecialCharacter(
        int i, int j, bool& marked,
        std::vector<std::string>& lines
        ) {
    if (!utils::isOutOfBounds(i ,j, lines.size(), lines[i].size())) {
        marked |= isSpecialChar(lines[i][j]);
        if (lines[i][j] == '*') currentGears.emplace_back(i, j);
    }
}

void setup() {
    currentGears.clear();
}

void update(int number, int& answer [[maybe_unused]]) {
    for (auto gear: currentGears) {
        if (gears.find(gear) == gears.end()) {
            gears[gear] = {number, -1};
        } else {
            if (gears[gear].second == -1) gears[gear].second = number;
            else gears[gear].first = -1;
        }
    }
}

void finalize(int& answer) {
    for (auto gear: gears) {
        if (gear.second.first != -1 && gear.second.second != -1)
            answer += gear.second.first * gear.second.second;
    }
}

int solver() {
    return solve(checkForSpecialCharacter, setup, update, finalize);
}

int gearRatios::secondPart() {
    return utils::solve(solver, input_file);
}