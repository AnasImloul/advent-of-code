#pragma once

#include <vector>
#include "../../utils/utils.h"

namespace cosmicExpansion {
    inline static std::string input_file = "../2023/day_11/in.txt";

    static const char GALAXY = '#';

    static std::vector<int> emptyColumns;
    static std::vector<int> emptyRows;
    static std::vector<std::pair<int, int>> galaxies;

    ll firstPart();
    ll secondPart();
    namespace {
        void setup(std::vector<std::string>& universe) {
            galaxies = std::vector<std::pair<int, int>>();
            emptyRows = std::vector<int>(universe.size() + 1, 1);
            emptyColumns = std::vector<int>(universe[0].size() + 1, 1);

            for (int row = 0; row < universe.size(); row++) {
                for (int col = 0; col < universe[row].size(); col++) {
                    if (universe[row][col] == GALAXY) {
                        galaxies.emplace_back(row, col);
                        emptyColumns[col + 1] = 0;
                        emptyRows[row + 1] = 0;
                    }
                }
            }

            for (int row = 1; row <= universe.size(); row++)
                emptyRows[row] += emptyRows[row - 1];

            for (int col = 1; col <= universe.size(); col++)
                emptyColumns[col] += emptyColumns[col - 1];
        }

        inline ll calculateColumnDistance(int col1, int col2, int expansionRate) {
            if (col1 > col2) std::swap(col1, col2);
            return (ll)(emptyColumns[col2 + 1] - emptyColumns[col1]) * (ll)(expansionRate - 1) + (col2 - col1);
        }

        inline ll calculateRowDistance(int row1, int row2, int expansionRate) {
            if (row1 > row2) std::swap(row1, row2);
            return (ll)(emptyRows[row2 + 1] - emptyRows[row1]) * (ll)(expansionRate - 1) + (row2 - row1);
        }

        ll calculateDistance(std::pair<int, int>& start, std::pair<int, int>& end, int expansionRate) {
            auto [row1, col1] = start;
            auto [row2, col2] = end;
            return calculateColumnDistance(col1, col2, expansionRate) + calculateRowDistance(row1, row2, expansionRate);
        }

        ll solve(int expansionRate) {
            std::vector<std::string> universe = utils::readLines();
            setup(universe);

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