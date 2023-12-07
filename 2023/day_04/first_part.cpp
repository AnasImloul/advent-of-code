#include <iostream>
#include "scratchcards.h"

using namespace scratchcards;

int solver() {
    int answer = 0;
    for (std::string& line : utils::readLines()) {
        answer += 1 << countMatches(line);
    }
    return answer >> 1;
}

int scratchcards::firstPart() {
    return utils::solve(solver, input_file);
}