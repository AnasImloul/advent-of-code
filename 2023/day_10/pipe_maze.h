#pragma once

#include <vector>
#include "../../utils/utils.h"

namespace pipeMaze {
    using Point = std::pair<int, int>;

    inline static std::string input_file = "../2023/day_11/in.txt";

    inline static std::string chars = "-|LJ7F";

    static std::vector<std::vector<bool>> visited;

    static const std::vector<std::vector<std::pair<int, int>>> neighbors = {
            {{0, -1}, {0, 1}},  // '-'
            {{-1, 0}, {1, 0}},  // '|'
            {{-1, 0}, {0, 1}},  // 'L'
            {{0, -1}, {-1, 0}}, // 'J'
            {{0, -1}, {1, 0}},  // '7'
            {{1, 0}, {0, 1}},    // 'F'
            {} // otherwise
    };

    static const std::vector<Point> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int firstPart();
    int secondPart();
    namespace {
        void setup(std::vector<std::string>& maze) {
            visited = std::vector<std::vector<bool>>(maze.size(), std::vector<bool>(maze[0].size(), false));
        }

        const std::vector<std::pair<int, int>>& getNeighbors(char c) {
            switch (c) {
                case '-': return neighbors[0];
                case '|': return neighbors[1];
                case 'L': return neighbors[2];
                case 'J': return neighbors[3];
                case '7': return neighbors[4];
                case 'F': return neighbors[5];
                default: return neighbors[6];
            };
        }

        Point getStartingPoint(std::vector<std::string>& lines) {
            for (int i = 0; i < (int)lines.size(); i++) {
                for (int j = 0; j < (int)lines[i].size(); j++) {
                    if (lines[i][j] == 'S') {
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        }

        [[maybe_unused]]
        bool isOutOfBounds(Point point, std::vector<std::string>& maze) {
            auto [y, x] = point;
            return y < 0 || y >= (int)maze.size() || x < 0 || x >= (int)maze[x].size();
        }

        bool getLoopElements(Point current, Point start, std::vector<std::string>& maze, std::vector<Point>& answer) {
            answer.push_back(start);
            do {
                auto [y, x] = current;
                visited[y][x] = true;
                answer.emplace_back(current);

                bool stuck = true, found = false;
                for (auto& [dy, dx] : getNeighbors(maze[y][x])) {
                    Point neighbor = {y + dy, x + dx};
                    if (neighbor == start) found = true;
                    if (visited[neighbor.first][neighbor.second]) continue;
                    current = neighbor;
                    stuck = false;
                    break;
                }
                if (stuck) return found;
            } while (true);
        }

        std::vector<Point> solveLoopElements(Point start, std::vector<std::string>& maze) {
            std::vector<Point> answer;
            for (auto& [dy, dx]: directions) {
                auto [y, x] = start;
                visited[y][x] = true;
                if (getLoopElements({y + dy, x + dx}, start, maze, answer)) return answer;
                answer.clear();
            }
            return {};
        }
    }
}