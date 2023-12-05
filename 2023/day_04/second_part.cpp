//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <vector>
#include "scratchcards.h"

using namespace scratchcards;


int solver() {
    std::vector<std::string> lines = readLines();
    std::vector<int> count(lines.size(), 1);

    for (int i = (int)lines.size() - 1; i >= 0; i--) {
        std::string line = lines[i];
        int match = countMatches(line);
        for (int j = i + 1; j <= std::min(i + match, (int)lines.size() - 1); j++)
            count[i] += count[j];
    }

    return utils::sum<int>(count);
}


int scratchcards::secondPart() {
    return scratchcards::solve(solver);
}
