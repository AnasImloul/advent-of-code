//
// Created by user on 02/12/2023.
//

#pragma once

#include <iostream>
#include "cube_conundrum.h"


int solver() {
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
    return cubeConundrum::solve(solver);
}

