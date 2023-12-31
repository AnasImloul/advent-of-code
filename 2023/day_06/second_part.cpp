#include <iostream>
#include <vector>
#include "wait_for_it.h"

using namespace waitForIt;

int solver() {
    std::vector<std::string> lines = utils::readLines();

    ll time = 0;
    int i = 0;
    while (i < (int)lines[0].size()) {
        utils::skipUntil(lines[0], i, [](char c){return (bool)isdigit(c);});
        while (i < (int)lines[0].size() && isdigit(lines[0][i])) {
            time = time * 10 + (lines[0][i] - '0');
            i++;
        }
    }

    ll distance = 0;
    int j = 0;
    while (j < (int)lines[1].size()) {
        utils::skipUntil(lines[1], j, [](char c){return (bool)isdigit(c);});
        while (j < (int)lines[1].size() && isdigit(lines[1][j])) {
            distance = distance * 10 + (lines[1][j] - '0');
            j++;
        }
    }

    return winningRecharges(time, distance);
}

int waitForIt::secondPart() {
    return utils::solve(solver, input_file);
}