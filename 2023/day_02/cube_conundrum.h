#pragma once

#include <array>
#include "../../utils/utils.h"


namespace cubeConundrum {
    inline static std::string input_file = "../2023/day_02/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        using Triplet = std::array<int, 3>;

        Triplet parse(const std::string& line) {
            int i = 0;
            utils::skipUntil(line, i, [](char c){return c == ':';});

            int red = 0, blue = 0, green = 0;
            while (i < (int)line.size()) {
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
