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
    using Graph = std::unordered_map<std::pair<int, int>, std::vector<std::pair<int, int>>, utils::hash_pair<int, int>>;

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

        Graph buildGraph(std::vector<std::string>& maze) {
            Graph graph;
            graph.reserve(maze.size() * maze[0].size());

            for (int i = 0; i < maze.size(); i++) {
                for (int j = 0; j < maze[i].size(); j++) {
                    if (neighborsMap.find(maze[i][j]) == neighborsMap.end()) continue;
                    for (auto& [dy, dx]: neighborsMap.at(maze[i][j])) {
                        std::pair<int, int> neighbor = {i + dy, j + dx};
                        if (!isOutOfBounds(neighbor.first, neighbor.second, maze)) {
                            graph[{i, j}].emplace_back(neighbor);
                        }
                    }
                }
            }
            return graph;
        }

        bool areConnected(std::pair<int, int> current, std::pair<int, int> neighbor, Graph& maze) {
            if (maze.find(current) == maze.end()) return false;
            if (maze.find(neighbor) == maze.end()) return false;

            if (std::find(maze[current].begin(), maze[current].end(), neighbor) == maze[current].end()) return false;
            if (std::find(maze[neighbor].begin(), maze[neighbor].end(), current) == maze[neighbor].end()) return false;

            return true;
        }

        std::vector<std::pair<int, int>> getLoopElements(std::pair<int, int> start, Graph& maze) {
            std::vector<std::pair<int, int>> loop;
            std::pair<int, int> current = start;
            visited.clear();

            do {
                auto [y, x] = current;
                visited.insert(current);
                loop.emplace_back(current);
                if (maze.find(current) == maze.end()) return {};

                bool stuck = true, found = false;
                for (auto& neighbor : maze[current]) {
                    if (neighbor == start) found = true;
                    if (visited.find(neighbor) == visited.end()) {
                        current = neighbor;
                        stuck = false;
                        break;
                    }
                }
                if (stuck) {
                    if (found && areConnected(start, current, maze)) return loop;
                    else return {};
                }
            } while (true);
        }

        std::vector<std::pair<int, int>> solveLoopElements(std::pair<int ,int> start, std::vector<std::string>& maze) {
            Graph graph = buildGraph(maze);
            for (auto& c: chars) {
                graph[start].clear();
                for (auto& [dy, dx] : neighborsMap.at(c)) {
                    std::pair<int, int> neighbor = {start.first + dy, start.second + dx};
                    if (!isOutOfBounds(neighbor.first, neighbor.second, maze)) {
                        graph[start].emplace_back(neighbor);
                    }
                }
                std::vector<std::pair<int, int>> loop = getLoopElements(start, graph);
                if (!loop.empty()) return loop;
            }
            return {};
        }

    }
}