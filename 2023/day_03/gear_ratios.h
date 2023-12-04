//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>


namespace gearRatios {
    int firstPart();
    int secondPart();
    namespace {
        using Solver = int();
        int solve(Solver solver) {
            std::streambuf *oldCin = std::cin.rdbuf();
            std::ifstream in("../2023/day_03/in.txt");
            std::cin.rdbuf(in.rdbuf());

            int answer = solver();

            std::cin.rdbuf(oldCin);
            return answer;
        }

        inline bool isSpecialChar(char c) {
            return !isdigit(c) && c != '.';
        }

        inline bool isOutOfBounds(int i, int j, int n, int m) {
            return i < 0 | i >= n | j < 0 | j >= m;
        }

        std::vector<std::string> readLines() {
            std::vector<std::string> lines;
            while (!std::cin.eof()) {
                std::string line;
                std::getline(std::cin, line);
                lines.push_back(line);
            }
            return lines;
        }
    }
}
