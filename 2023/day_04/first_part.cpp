//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <vector>
#include "scratchcards.h"
#include <cstring>

using namespace scratchcards;


int solver() {
    int answer = 0;

    for (std::string& line : readLines()) {
        answer += 1 << countMatches(line);
    }

    return answer >> 1;
}


int scratchcards::firstPart() {
    return scratchcards::solve(solver);
}

