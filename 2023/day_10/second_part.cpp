#include <stack>
#include <algorithm>
#include "pipe_maze.h"

using namespace pipeMaze;

#include <iostream>
#include <vector>


int solver() {
    std::vector<std::string> maze = utils::readLines();

    std::pair<int, int> pos = pipeMaze::getStartingPoint(maze);

    std::vector<std::pair<int, int>> loop_elements = solveLoopElements(pos, maze);

    visited.clear();

    for (auto &p: loop_elements) {
        visited.insert(p);
    }

    int answer = 0;

    std::vector<std::pair<int, int>> polygon = utils::reducePolygon(loop_elements);

    for (int y = 0; y < maze.size(); y++) {
        for (int x = 0; x < maze[y].size(); x++) {
            if (visited.find({y, x}) == visited.end()) {
                if (utils::isPointInsidePolygon(y, x, polygon)) {
                    answer++;
                }
            }
        }
    }

    return answer;
}

int pipeMaze::secondPart() {
    return utils::solve(solver, input_file);
}