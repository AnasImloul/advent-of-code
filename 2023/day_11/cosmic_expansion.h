#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include "../../utils/utils.h"


namespace cosmicExpansion {
    inline static std::string input_file = "../2023/day_11/in.txt";

    static const char GALAXY = '#';

    static std::vector<int> emptyColumns;
    static std::vector<int> emptyRows;

    ll firstPart();
    ll secondPart();
    namespace {
        std::vector<std::pair<int, int>> getGalaxies(std::vector<std::string>& universe) {
            std::vector<std::pair<int, int>> galaxies;
            for (int row = 0; row < universe.size(); row++) {
                for (int col = 0; col < universe[row].size(); col++) {
                    if (universe[row][col] == GALAXY) galaxies.emplace_back(row, col);
                }
            }
            return galaxies;
        }

        bool isRowEmpty(std::vector<std::string>& universe, int row) {
            for (int col = 0; col < universe[row].size(); col++) {
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

        void setup(std::vector<std::string>& universe) {
            emptyRows = std::vector<int>(universe.size());
            for (int row = 0; row < universe.size(); row++) {
                if (isRowEmpty(universe, row)) emptyRows[row] = 1;
                if (row != 0) emptyRows[row] += emptyRows[row - 1];
            }

            emptyColumns = std::vector<int>(universe[0].size());
            for (int col = 0; col < universe.size(); col++) {
                if (isColumnEmpty(universe, col)) emptyColumns[col] = 1;
                if (col != 0) emptyColumns[col] += emptyColumns[col - 1];
            }
        }

        inline ll calculateColumnDistance(int col1, int col2, int expansionRate) {
            if (col1 > col2) std::swap(col1, col2);
            return (emptyColumns[col2] - (col1 != 0 ? emptyColumns[col1] : 0)) * (ll)(expansionRate - 1) + (col2 - col1);
        }

        inline ll calculateRowDistance(int row1, int row2, int expansionRate) {
            if (row1 > row2) std::swap(row1, row2);
            return (emptyRows[row2] - (row1 != 0 ? emptyRows[row1] : 0)) * (ll)(expansionRate - 1) + (row2 - row1);
        }

        ll calculateDistance(std::pair<int, int>& start, std::pair<int, int>& end, int expansionRate) {
            auto [row1, col1] = start;
            auto [row2, col2] = end;
            return calculateColumnDistance(col1, col2, expansionRate) + calculateRowDistance(row1, row2, expansionRate);
        }

        ll solve(int expansionRate) {
            std::vector<std::string> universe = utils::readLines();
            setup(universe);

            std::vector<std::pair<int, int>> galaxies = getGalaxies(universe);

            ll answer = 0;
            for (int i = 0; i < galaxies.size(); i++) {
                for (int j = i + 1; j < galaxies.size(); j++) {
                    answer += calculateDistance(galaxies[i], galaxies[j], expansionRate);
                }
            }

            return answer;
        }
    }
}