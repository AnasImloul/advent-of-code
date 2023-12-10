#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cstdint>
#include <array>
#include <unordered_set>
#include <algorithm>
#include "../../utils/utils.h"


namespace pipeMaze {
    using Point = std::pair<int, int>;

    using NeighborsMap = std::unordered_map<char, std::vector<Point>>;

    inline static std::string input_file = "../2023/day_10/in.txt";

    inline static std::string chars = "-|LJ7F";

    static std::vector<std::vector<bool>> visited;

    static const NeighborsMap neighborsMap = {
            {'-', {{0, -1}, {0, 1}}},
            {'|', {{-1, 0}, {1, 0}}},
            {'L', {{-1, 0}, {0, 1}}},
            {'J', {{0, -1}, {-1, 0}}},
            {'7', {{0, -1}, {1, 0}}},
            {'F', {{1, 0}, {0, 1}}}
    };

    static const std::vector<Point> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };

    int firstPart();
    int secondPart();

    namespace {
        void setup(std::vector<std::string>& maze) {
            visited = std::vector<std::vector<bool>>(maze.size(), std::vector<bool>(maze[0].size(), false));
        }

        Point getStartingPoint(std::vector<std::string>& lines) {
            for (int i = 0; i < lines.size(); i++) {
                for (int j = 0; j < lines[i].size(); j++) {
                    if (lines[i][j] == 'S') {
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        }

        bool isOutOfBounds(Point point, std::vector<std::string>& maze) {
            auto [y, x] = point;
            return y < 0 || y >= maze.size() || x < 0 || x >= maze[x].size();
        }

        std::vector<Point> getLoopElements(Point current, Point start, std::vector<std::string>& maze) {
            std::vector<Point> loop(1, start);
            do {
                auto [y, x] = current;
                visited[y][x] = true;
                loop.emplace_back(current);
                if (neighborsMap.find(maze[y][x]) == neighborsMap.end()) return {};

                bool stuck = true, found = false;
                for (auto& [dy, dx] : neighborsMap.at(maze[y][x])) {
                    Point neighbor = {y + dy, x + dx};
                    if (neighbor == start) found = true;
                    if (visited[neighbor.first][neighbor.second]) continue;
                    current = neighbor;
                    stuck = false;
                    break;
                }
                if (stuck) {
                    if (found) return loop;
                    else return {};
                }
            } while (true);
        }

        std::vector<Point> solveLoopElements(std::pair<int ,int> start, std::vector<std::string>& maze) {
            for (auto& [dy, dx]: directions) {
                auto [y, x] = start;
                visited[y][x] = true;
                std::vector<Point> loop = getLoopElements({y + dy, x + dx}, start, maze);
                if (!loop.empty()) return loop;
            }
            return {};
        }
    }
}