#include <stack>
#include <algorithm>
#include "pipe_maze.h"

using namespace pipeMaze;

#include <iostream>
#include <vector>

// iterative DFS to find the number of elements connected to a position
int dfs(std::pair<int, int> current, std::vector<std::string>& maze) {
    std::stack<std::pair<int, int>> stack;

    stack.push(current);

    int answer = 0;
    while (!stack.empty()) {
        std::pair<int, int> pos = stack.top();
        stack.pop();

        if (visited[pos.first][pos.second]) {
            continue;
        }

        visited[pos.first][pos.second] = true;

        answer++;
        for (auto& [dy, dx] : directions) {
            std::pair<int, int> neighbor = {pos.first + dy, pos.second + dx};
            if (isOutOfBounds(neighbor.first, neighbor.second, maze)) continue;
            if (visited[neighbor.first][neighbor.second]) continue;
            stack.push(neighbor);
        }
    }

    return answer;
}


int solver() {
    std::vector<std::string> maze = utils::readLines();

    setup(maze);

    std::pair<int, int> pos = pipeMaze::getStartingPoint(maze);

    std::vector<std::pair<int, int>> loop_elements = solveLoopElements(pos, maze);
    for (auto& p: loop_elements) {
        visited[p.first][p.second] = true;
    }

    int answer = 0;

    std::vector<std::pair<int, int>> polygon = utils::reducePolygon(loop_elements);

    for (int y = 0; y < maze.size(); y++) {
        for (int x = 0; x < maze[y].size(); x++) {
            if (!visited[y][x]) {
                int size = dfs({y, x}, maze);
                if (utils::isPointInsidePolygon(y, x, polygon)) {
                    answer += size;
                }
            }
        }
    }

    return answer;
}

int pipeMaze::secondPart() {
    return utils::solve(solver, input_file);
}