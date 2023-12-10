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
    using NeighborsMap = std::unordered_map<char, std::vector<std::pair<int, int>>>;

    inline static std::string input_file = "../2023/day_10/in.txt";

    inline static std::string chars = "-|LJ7F";

    static std::unordered_set<std::pair<int, int>, utils::hash_pair<int, int>> visited;

    static const NeighborsMap neighborsMap = {
            {'-', {{0, -1}, {0, 1}}},
            {'|', {{-1, 0}, {1, 0}}},
            {'L', {{-1, 0}, {0, 1}}},
            {'J', {{0, -1}, {-1, 0}}},
            {'7', {{0, -1}, {1, 0}}},
            {'F', {{1, 0}, {0, 1}}}
    };

    static const std::vector<std::pair<int, int>> directions = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };

    int firstPart();
    int secondPart();

    namespace {
        std::pair<int, int> getStartingPoint(std::vector<std::string>& lines) {
            for (int i = 0; i < lines.size(); i++) {
                for (int j = 0; j < lines[i].size(); j++) {
                    if (lines[i][j] == 'S') {
                        return {i, j};
                    }
                }
            }
            return {-1, -1};
        }

        bool isOutOfBounds(int y, int x, std::vector<std::string>& maze) {
            return y < 0 || y >= maze.size() || x < 0 || x >= maze[x].size();
        }


        std::vector<std::pair<int, int>> getLoopElements(std::pair<int, int> current, std::pair<int, int> start, std::vector<std::string>& maze) {
            std::vector<std::pair<int, int>> loop(1, start);
            visited.clear();

            visited.insert(start);

            do {
                auto [y, x] = current;
                visited.insert(current);
                loop.emplace_back(current);
                if (neighborsMap.find(maze[y][x]) == neighborsMap.end()) return {};

                bool stuck = true, found = false;
                for (auto& [dy, dx] : neighborsMap.at(maze[y][x])) {
                    std::pair<int, int> neighbor = {y + dy, x + dx};
                    if (neighbor == start) found = true;
                    if (visited.find(neighbor) == visited.end()) {
                        current = neighbor;
                        stuck = false;
                        break;
                    }
                }
                if (stuck) {
                    if (found) return loop;
                    else return {};
                }
            } while (true);
        }

        std::vector<std::pair<int, int>> solveLoopElements(std::pair<int ,int> start, std::vector<std::string>& maze) {
            for (auto& [dy, dx]: directions) {
                auto [y, x] = start;
                std::vector<std::pair<int, int>> loop = getLoopElements({y + dy, x + dx}, start, maze);
                if (!loop.empty()) return loop;
            }
            return {};
        }

    }
}