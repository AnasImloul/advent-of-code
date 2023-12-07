#include <iostream>
#include <vector>
#include "gear_ratios.h"
#include "../../utils.h"

using namespace gearRatios;


void checkForSpecialCharacter(
        int i, int j, bool& marked,
        std::vector<std::string>& lines) {
    if (!utils::isOutOfBounds(i, j, (int)lines.size(), (int)lines[i].size())) {
        marked |= isSpecialChar(lines[i][j]);
    }
}

void setup() {}

void update(int number ,int& answer) { answer += number; }

void finalize(int& answer) {}


int solver() {
    return solve(checkForSpecialCharacter, setup, update, finalize);
}

int gearRatios::firstPart() {
    return utils::solve(solver, input_file);
}