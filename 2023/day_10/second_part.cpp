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

        if (visited[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;

        answer++;
        for (auto& [dy, dx] : directions) {
            std::pair<int, int> neighbor = {pos.first + dy, pos.second + dx};
            if (isOutOfBounds(neighbor, maze)) continue;
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

    for (auto& p: loop_elements)
        visited[p.first][p.second] = true;

    std::vector<std::pair<int, int>> polygon = utils::reducePolygon(loop_elements);

    int answer = 0;
    for (int i = 0; i < (int)maze.size(); i++) {
        for (int j = 0; j < (int)maze[i].size(); j++) {
            if (!visited[i][j]) {
                std::pair<int, int> point = {i, j};
                int size = dfs(point, maze);
                if (utils::isPointInsidePolygon(point, polygon)) {
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