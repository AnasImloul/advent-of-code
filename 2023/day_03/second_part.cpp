//
// Created by user on 03/12/2023.
//


#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include "gear_ratios.h"


using namespace gearRatios;

template <class T1, class T2>
struct hash_pair {
    size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);

        if (hash1 != hash2) return hash1 ^ hash2;
        return hash1;
    }
};

int solver() {
    int answer = 0;
    std::vector<std::string> lines = readLines();
    std::unordered_map<std::pair<int, int>, std::pair<int, int>, hash_pair<int, int>> gears;

    int n = lines.size();
    for (int i = 0; i < n; i++) {
        int m = lines[i].size(), j = 0;
        while (j < m) {
            while (j < m && !isdigit(lines[i][j])) j++;

            bool marked = false;
            std::vector<std::pair<int, int>> currentGears;

            if (!isOutOfBounds(i - 1 ,j - 1, n, m)) {
                marked |= isSpecialChar(lines[i - 1][j - 1]);
                if (lines[i - 1][j - 1] == '*') currentGears.push_back({i - 1, j - 1});
            }
            if (!isOutOfBounds(i ,j - 1, n, m)) {
                marked |= isSpecialChar(lines[i][j - 1]);
                if (lines[i][j - 1] == '*') currentGears.push_back({i, j - 1});
            }
            if (!isOutOfBounds(i + 1 ,j - 1, n, m)) {
                marked |= isSpecialChar(lines[i + 1][j - 1]);
                if (lines[i + 1][j - 1] == '*') currentGears.push_back({i + 1, j - 1});
            }

            int number = 0;
            while (j < m && isdigit(lines[i][j])) {
                if (!isOutOfBounds(i - 1 ,j, n, m)) {
                    marked |= isSpecialChar(lines[i - 1][j]);
                    if (lines[i - 1][j] == '*') currentGears.push_back({i - 1, j});
                }
                if (!isOutOfBounds(i ,j, n, m)) {
                    marked |= isSpecialChar(lines[i][j]);
                    if (lines[i][j] == '*') currentGears.push_back({i, j});
                }
                if (!isOutOfBounds(i + 1 ,j, n, m)) {
                    marked |= isSpecialChar(lines[i + 1][j]);
                    if (lines[i + 1][j] == '*') currentGears.push_back({i + 1, j});
                }

                number = number * 10 + (lines[i][j] - '0');
                j++;
            }

            if (!isOutOfBounds(i - 1 ,j, n, m)) {
                marked |= isSpecialChar(lines[i - 1][j]);
                if (lines[i - 1][j] == '*') currentGears.push_back({i - 1, j});
            }
            if (!isOutOfBounds(i ,j, n, m)) {
                marked |= isSpecialChar(lines[i][j]);
                if (lines[i][j] == '*') currentGears.push_back({i, j});
            }
            if (!isOutOfBounds(i + 1 ,j, n, m)) {
                marked |= isSpecialChar(lines[i + 1][j]);
                if (lines[i + 1][j] == '*') currentGears.push_back({i + 1, j});
            }

            if (!marked) continue;

            for (auto gear: currentGears) {
                if (gears.find(gear) == gears.end()) {
                    gears[gear] = {number, -1};
                } else {
                    if (gears[gear].second == -1) {
                        gears[gear].second = number;
                    } else {
                        gears[gear].first = -1;
                    }
                }
            }
        }
    }

    for (auto gear: gears) {
        if (gear.second.first != -1 && gear.second.second != -1) {
            answer += gear.second.first * gear.second.second;
        }
    }

    return answer;
}


int gearRatios::secondPart() {
    return gearRatios::solve(solver);
}


