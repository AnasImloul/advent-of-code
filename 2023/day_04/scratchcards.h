//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "../../utils.h"


namespace scratchcards {
    int firstPart();
    int secondPart();
    namespace {
        using Solver = int();
        int solve(Solver solver) {
            std::streambuf *oldCin = std::cin.rdbuf();
            std::ifstream in("../2023/day_04/in.txt");
            std::cin.rdbuf(in.rdbuf());

            int answer = solver();

            std::cin.rdbuf(oldCin);
            return answer;
        }

        int countMatches(const std::string& line) {
            static bool winner[100];
            memset(winner, false, sizeof(winner));

            int match = 0, i = 0;

            utils::skipUntil(line, i, [](char c){return c == ':';});

            i++;
            while (i < line.size()) {
                utils::skipUntil(line, i, [](char c){return c != ' ';});

                if (line[i] == '|') break;

                int number = utils::nextInt(line, i);

                winner[number] = true;
            }

            while (i < line.size()) {
                utils::skipUntil(line, i, [](char c){return (bool)isdigit(c);});

                int number = utils::nextInt(line, i);

                if (winner[number]) match++;
            }

            return match;
        }
    }
}
