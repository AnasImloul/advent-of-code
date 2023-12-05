//
// Created by user on 01/12/2023.
//

#pragma once

#include <fstream>
#include <iostream>

namespace trebuchet {
    inline static std::string input_string = "../2023/day_01/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        using Parser = int(const std::string&);
    }
}

