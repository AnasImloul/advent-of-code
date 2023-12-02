//
// Created by user on 02/12/2023.
//

#pragma once

#include <array>
#include <fstream>

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
            while (i < line.size() && line[i] != ':') {
                i++;
            }
            // increment two to account for the ':' & the white space after it
            i += 2;

            int red = 0, blue = 0, green = 0;
            while (i < line.size()) {
                int amount = 0;
                while (i < line.size() && isdigit(line[i])) {
                    amount = amount * 10 + (line[i] - '0');
                    i++;
                }

                // increment one to account for the white space after each digit
                i++;

                if (line[i] == 'r') red = std::max(red, amount);
                else if (line[i] == 'g') green = std::max(green, amount);
                else if (line[i] == 'b') blue = std::max(blue, amount);

                while (i < line.size() && line[i] != ',' && line[i] != ';') {
                    i++;
                }

                // increment two to account for the colon & the whitespace
                i += 2;
            }

            return {red, green, blue};
        }
    }
}
