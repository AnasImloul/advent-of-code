//
// Created by user on 01/12/2023.
//

#pragma once

#include <fstream>
#include <iostream>

using Parser = int(const std::string&);

namespace trebuchet {
    int firstPart();
    int secondPart();
    namespace {
        int solve(Parser parser) {
            std::streambuf *oldCin = std::cin.rdbuf();
            std::ifstream in("../2023/day_01/in.txt");
            std::cin.rdbuf(in.rdbuf());

            int answer = 0;
            std::string line;
            while (std::cin >> line) {
                answer += parser(line);
            }

            std::cin.rdbuf(oldCin);
            return answer;
        }
    }
}

