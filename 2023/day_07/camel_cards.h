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
#include <array>
#include "../../utils.h"


namespace camelCards {
    inline static std::string input_file = "../2023/day_07/in.txt";

    int firstPart();
    int secondPart();

    namespace {
        using CardToNumber = int (const char& c);

        int calculateStrength(const std::string &hand, int score, CardToNumber cardToNumber) {
            return (score << 20) +
                   (cardToNumber(hand[0]) << 16) +
                   (cardToNumber(hand[1]) << 12) +
                   (cardToNumber(hand[2]) << 8) +
                   (cardToNumber(hand[3]) << 4) +
                   (cardToNumber(hand[4]) << 0);
        }

        int getHandType(const std::string &hand) {
            static int count[256];
            memset(count, 0, sizeof(count));
            for (const char& card: hand) {
                count[card]++;
            }

            static int repeated[6];
            memset(repeated, 0, sizeof(repeated));

            for (int& c: count) {
                repeated[c]++;
            }

            int score;

            if (repeated[5] == 1) score = 6;
            else if (repeated[4] == 1) score = 5;
            else if (repeated[3] == 1 && repeated[2] == 1) score = 4;
            else if (repeated[3] == 1 && repeated[2] == 0) score = 3;
            else if (repeated[2] == 2) score = 2;
            else if (repeated[2] == 1) score = 1;
            else score = 0;

            return score;
        }
    }
}
