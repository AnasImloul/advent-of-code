//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <vector>
#include "gear_ratios.h"

using namespace gearRatios;

int solver() {
    int answer = 0;

    std::vector<std::string> lines = readLines();

    int n = lines.size();
    for (int i = 0; i < n; i++) {
        int m = lines[i].size(), j = 0;
        while (j < m) {
            while (j < m && !isdigit(lines[i][j])) {
                j++;
            }

            bool marked = false;

            if (!isOutOfBounds(i - 1 ,j - 1, n, m)) marked |= isSpecialChar(lines[i - 1][j - 1]);
            if (!isOutOfBounds(i ,j - 1, n, m)) marked |= isSpecialChar(lines[i][j - 1]);
            if (!isOutOfBounds(i + 1 ,j - 1, n, m)) marked |= isSpecialChar(lines[i + 1][j - 1]);

            int number = 0;
            while (j < m && isdigit(lines[i][j])) {
                if (!isOutOfBounds(i - 1 ,j, n, m)) marked |= isSpecialChar(lines[i - 1][j]);
                if (!isOutOfBounds(i ,j, n, m)) marked |= isSpecialChar(lines[i][j]);
                if (!isOutOfBounds(i + 1 ,j, n, m)) marked |= isSpecialChar(lines[i + 1][j]);

                number = number * 10 + (lines[i][j] - '0');
                j++;
            }

            if (!isOutOfBounds(i - 1 ,j, n, m)) marked |= isSpecialChar(lines[i - 1][j]);
            if (!isOutOfBounds(i ,j, n, m)) marked |= isSpecialChar(lines[i][j]);
            if (!isOutOfBounds(i + 1 ,j, n, m)) marked |= isSpecialChar(lines[i + 1][j]);


            if (marked) answer += number;

        }
    }

    return answer;
}


int gearRatios::firstPart() {
    return gearRatios::solve(solver);
}

