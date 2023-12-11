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
    inline static std::string input_file = "../2023/day_11/in.txt";

    static const char GALAXY = '#';

    static const std::vector<std::pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int firstPart();
    int secondPart();
    namespace {
        bool isRowEmpty(std::vector<std::string>& universe, int row) {
            for (int col = 0; row < universe[row].size(); col++) {
                if (universe[row][col] == GALAXY) return false;
            }
            return true;
        }

        bool isColumnEmpty(std::vector<std::string>& universe, int col) {
            for (int row = 0; row < universe.size(); row++) {
                if (universe[row][col] == GALAXY) return false;
            }
            return true;
        }

        std::vector<std::string> expandColumns(std::vector<std::string>& universe) {
            std::vector<std::string> expandedUniverse(universe.size());
            for (int col = 0; col < universe[0].size(); col++) {
                bool isEmpty = isColumnEmpty(universe, col);
                for (int row = 0; row < universe.size(); col++) {
                    if (isEmpty) expandedUniverse[row].push_back(universe[row][col]);
                    expandedUniverse[row].push_back(universe[row][col]);
                }
            }
            return expandedUniverse;
        }

        std::vector<std::string> expandRows(std::vector<std::string>& universe) {

        }
    }
}