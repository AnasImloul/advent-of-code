//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>


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

        int countMatches(std::string& line) {
            bool winner[100];
            memset(winner, false, sizeof(winner));

            int match = 0, i = 0;

            while (i < line.size() && line[i] != ':')
                i++;

            i++;
            while (i < line.size()) {
                while (i < line.size() && line[i] == ' ')
                    i++;

                if (line[i] == '|') break;

                int number = 0;
                while (i < line.size() && isdigit(line[i]))
                    number = number * 10 + (line[i++] - '0');

                winner[number] = true;
            }

            while (i < line.size()) {
                while (i < line.size() && !isdigit(line[i]))
                    i++;

                int number = 0;
                while (i < line.size() && isdigit(line[i]))
                    number = number * 10 + (line[i++] - '0');

                if (winner[number]) match++;
            }

            return match;
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
