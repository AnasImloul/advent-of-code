//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>


namespace gearRatios {
    inline static std::string input_string = "../2023/day_03/in.txt";
    int firstPart();
    int secondPart();
    namespace {
        inline bool isSpecialChar(char c) {
            return !isdigit(c) && c != '.';
        }
    }
}
