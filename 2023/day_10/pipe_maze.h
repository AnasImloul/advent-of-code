#pragma once

#include <vector>
#include "../../utils/utils.h"
#include "../../utils/Advent.h"


namespace pipeMaze {
    using Point = std::pair<int, int>;

    class PipeMaze : public Advent {

    protected:
        PipeMaze() : Advent(input_file) {
            maze = utils::readLines(in);
            visited = std::vector<std::vector<bool>>(maze.size(), std::vector<bool>(maze[0].size(), false));
        }

        std::vector<Point> getLoopElements() {
            Point start = getStartingPoint();
            std::vector<Point> answer;
            for (auto& [dy, dx]: directions) {
                auto [y, x] = start;
                visited[y][x] = true;
                if (getLoopElementsHelper({y + dy, x + dx}, start, answer)) return answer;
                answer.clear();
            }
            return {};
        }

        [[maybe_unused]]
        bool isOutOfBounds(Point point) {
            auto [y, x] = point;
            return y < 0 || y >= (int)maze.size() || x < 0 || x >= (int)maze[x].size();
        }

        Point getStartingPoint() {
            for (int i = 0; i < (int)maze.size(); i++) {
                for (int j = 0; j < (int)maze[i].size(); j++) {
                    if (maze[i][j] == 'S') {
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        }

        static const std::vector<std::pair<int, int>>& getNeighbors(char c) {
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

        bool getLoopElementsHelper(Point current, Point start, std::vector<Point>& answer) {
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

        inline static std::string input_file = "../2023/day_10/in.txt";

        inline static const std::vector<std::vector<std::pair<int, int>>> neighbors = {
                {{0, -1}, {0, 1}},  // '-'
                {{-1, 0}, {1, 0}},  // '|'
                {{-1, 0}, {0, 1}},  // 'L'
                {{0, -1}, {-1, 0}}, // 'J'
                {{0, -1}, {1, 0}},  // '7'
                {{1, 0}, {0, 1}},    // 'F'
                {} // otherwise
        };

        inline static const std::vector<Point> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        std::vector<std::string> maze;
        std::vector<std::vector<bool>> visited;


    };
}