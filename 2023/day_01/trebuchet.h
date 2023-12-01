//
// Created by user on 01/12/2023.
//

#pragma once

using Parser = int(const std::string&);


namespace trebuchet {
    int firstPart();
    int secondPart();
    namespace {
        int solve(Parser parser) {
            int answer = 0;
            std::string line;
            while (std::cin >> line) {
                answer += parser(line);
            }
            return answer;
        }
    }
}

