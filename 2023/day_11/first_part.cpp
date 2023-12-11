#include "cosmic_expansion.h"

using namespace pipeMaze;

int solver() {
    std::vector<std::string> maze = utils::readLines();
    setup(maze);
    std::pair<int, int> pos = pipeMaze::getStartingPoint(maze);
    return (int)solveLoopElements(pos, maze).size() / 2;
}

int pipeMaze::firstPart() {
    return utils::solve(solver, input_file);
}