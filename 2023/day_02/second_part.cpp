//
// Created by user on 02/12/2023.
//


#include <iostream>
#include "cube_conundrum.h"


using namespace cubeConundrum;


int solve() {
    int answer = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        auto [r, g, b] = cubeConundrum::parse(line);
        answer += r * g * b;
    }
    return answer;
}

int cubeConundrum::secondPart() {
    return utils::solve(solve, input_file);
}