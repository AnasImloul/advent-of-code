//
// Created by user on 03/12/2023.
//
#include <iostream>
#include <vector>
#include "wait-for-it.h"
#include <cstdint>

using namespace waitForIt;

int solver() {
    std::vector<std::string> lines = utils::readLines();

    std::vector<int> times = utils::parseIntegers(lines[0]);
    std::vector<int> distances = utils::parseIntegers(lines[1]);

    int answer = 1;

    for (int i = 0; i < times.size(); i++) {
        answer *= winningRecharges(times[i], distances[i]);
    }

    return answer;
}

int waitForIt::firstPart() {
    return utils::solve(solver, input_file);
}