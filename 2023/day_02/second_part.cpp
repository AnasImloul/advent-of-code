//
// Created by user on 02/12/2023.
//
#pragma once

#include <iostream>
#include "cube_conundrum.h"

int solver() {
    int answer = 0;
    std::string line;
    while (!std::cin.eof() && std::getline(std::cin, line)) {
        auto [r, g, b] = cubeConundrum::parse(line);
        answer += r * g * b;
    }
    return answer;
}

int cubeConundrum::secondPart() {
    return cubeConundrum::solve(solver);
}