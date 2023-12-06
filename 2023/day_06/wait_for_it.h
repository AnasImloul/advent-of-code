//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include <cstdint>
#include "../../utils.h"


namespace waitForIt {
    inline static std::string input_file = "../2023/day_06/in.txt";

    int firstPart();
    int secondPart();

    namespace {
        int winningRecharges(ll time, ll distance) {
            int winning = 0;
            // there is plenty of room to optimizations
            // the inequality can be seen as finding where a f(t) = t * (time - t) - distance is positive
            // hint: find the root of a second degree polynomial
            // however the current implementation is cleaner, so i'll leave it as it is
            for (ll t = 0; t <= time; t++) {
                if (t * (time - t) >= distance) winning++;
            }
            return winning;
        }
    }
}
