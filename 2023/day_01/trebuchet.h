#pragma once

#include <fstream>
#include <iostream>

namespace trebuchet {
    inline static std::string input_file = "../2023/day_01/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        using Parser = int(const std::string&);
    }
}

