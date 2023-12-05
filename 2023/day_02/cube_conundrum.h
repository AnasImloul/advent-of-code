//
// Created by user on 02/12/2023.
//

#pragma once

#include <array>
#include <fstream>
#include "../../utils.h"


namespace cubeConundrum {
    int firstPart();
    int secondPart();
    namespace {
        using Solver = int();
        int solve(Solver solver) {
            std::streambuf *oldCin = std::cin.rdbuf();
            std::ifstream in("../2023/day_02/in.txt");
            std::cin.rdbuf(in.rdbuf());

            int answer = solver();

            std::cin.rdbuf(oldCin);
            return answer;
        }

        std::array<int, 3> parse(const std::string& line) {

            int i = 0;
            utils::skipUntil(line, i, [](char c){return c == ':';});

            int red = 0, blue = 0, green = 0;
            while (i < line.size()) {
                utils::skipUntil(line, i, [](char c){return (bool)isdigit(c);});

                int amount = utils::nextInt(line, i);

                utils::skipUntil(line, i, [](char c){return c != ' ';});

                if (line[i] == 'r') red = std::max(red, amount);
                else if (line[i] == 'g') green = std::max(green, amount);
                else if (line[i] == 'b') blue = std::max(blue, amount);

                utils::skipUntil(line, i, [](char c){return c == ',' || c == ';';});
            }

            return {red, green, blue};
        }
    }
}
