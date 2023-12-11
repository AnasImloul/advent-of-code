#pragma once

#include <vector>
#include <cstring>
#include "../../utils/utils.h"


namespace scratchcards {
    inline static std::string input_file = "../2023/day_04/in.txt";
    int firstPart();
    int secondPart();
    namespace {
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
