//
// Created by user on 02/12/2023.
//


#include <iostream>
#include "cube_conundrum.h"

using namespace cubeConundrum;

int solve() {
    int answer = 0, id = 1;
    std::string line;
    while (std::getline(std::cin, line)) {
        auto [r, g, b] = cubeConundrum::parse(line);
        if (r <= 12 && g <= 13 && b <= 14) answer += id;
        id++;
    }
    return answer;
}


int cubeConundrum::firstPart() {
    return utils::solve(solve, input_file);
}
