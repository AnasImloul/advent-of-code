#pragma once

#include <vector>
#include "../../utils/utils.h"
#include "../../utils/Advent.h"


namespace cosmicExpansion {
    class CosmicExpansion : public Advent {

        inline ll calculateColumnDistance(int col1, int col2, int expansionRate) {
            if (col1 > col2) std::swap(col1, col2);
            return (ll) (emptyColumns[col2 + 1] - emptyColumns[col1]) * (ll) (expansionRate - 1) + (col2 - col1);
        }

        inline ll calculateRowDistance(int row1, int row2, int expansionRate) {
            if (row1 > row2) std::swap(row1, row2);
            return (ll) (emptyRows[row2 + 1] - emptyRows[row1]) * (ll) (expansionRate - 1) + (row2 - row1);
        }

        ll calculateDistance(std::pair<int, int> &start, std::pair<int, int> &end, int expansionRate) {
            auto [row1, col1] = start;
            auto [row2, col2] = end;
            return calculateColumnDistance(col1, col2, expansionRate) + calculateRowDistance(row1, row2, expansionRate);
        }

    protected:
        CosmicExpansion() : Advent(input_file) {
            universe = utils::readLines(in);
            galaxies = std::vector<std::pair<int, int>>();
            emptyRows = std::vector<int>(universe.size() + 1, 1);
            emptyColumns = std::vector<int>(universe[0].size() + 1, 1);

            for (int row = 0; row < (int)universe.size(); row++) {
                for (int col = 0; col < (int)universe[row].size(); col++) {
                    if (universe[row][col] == GALAXY) {
                        galaxies.emplace_back(row, col);
                        emptyColumns[col + 1] = 0;
                        emptyRows[row + 1] = 0;
                    }
                }
            }

            for (int row = 1; row <= (int)universe.size(); row++)
                emptyRows[row] += emptyRows[row - 1];

            for (int col = 1; col <= (int)universe.size(); col++)
                emptyColumns[col] += emptyColumns[col - 1];
        }

        ll calculatePairDistances(int expansionRate) {
            ll answer = 0;
            for (int i = 0; i < (int)galaxies.size(); i++) {
                for (int j = i + 1; j < (int)galaxies.size(); j++) {
                    answer += calculateDistance(galaxies[i], galaxies[j], expansionRate);
                }
            }
            return answer;
        }

    private:
        inline static std::string input_file = "../2023/day_11/in.txt";
        static const char GALAXY = '#';

        std::vector<std::string> universe;
        std::vector<int> emptyColumns;
        std::vector<int> emptyRows;
        std::vector<std::pair<int, int>> galaxies;

    };
}