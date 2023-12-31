#pragma once

#include "../../utils/utils.h"

namespace waitForIt {
    inline static std::string input_file = "../2023/day_06/in.txt";

    int firstPart();
    int secondPart();

    namespace {
        int winningRecharges(ll time, ll distance) {
            int winning = 0;
            // there is plenty of room for optimizations
            // the inequality can be seen as finding where this function f(t) = t * (time - t) - distance is positive
            // hint: find the roots of a second degree polynomial
            // however the current implementation is cleaner, so i'll leave it as it is
            for (ll t = 0; t <= time; t++) {
                if (t * (time - t) >= distance) winning++;
            }
            return winning;
        }
    }
}
