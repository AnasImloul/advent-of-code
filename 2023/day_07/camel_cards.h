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
        using SortingAlgorithm = void (std::vector<std::pair<std::string, int>>& hands);

        int cardToNumber(const char &c, const std::string& cards) {
            for (int i = 0; i < cards.size(); i++) {
                if (c == cards[i]) return i;
            }
            return 0;
        }

        int calculateStrength(const std::string &hand, int score, const std::string& cards) {
            return (score << 20) +
                   (cardToNumber(hand[0], cards) << 16) +
                   (cardToNumber(hand[1], cards) << 12) +
                   (cardToNumber(hand[2], cards) << 8) +
                   (cardToNumber(hand[3], cards) << 4) +
                   (cardToNumber(hand[4], cards) << 0);
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

        int solve(SortingAlgorithm sortingAlgorithm) {
            std::vector<std::string> lines = utils::readLines();

            std::vector<std::pair<std::string, int>> hands;

            for (std::string& line : lines) {
                std::string hand = line.substr(0, 5);

                int i = 6;
                int bid = utils::nextInt(line, i);
                hands.emplace_back(hand, bid);
            }

            sortingAlgorithm(hands);

            int answer = 0;
            for (int i = 0; i < hands.size(); i++) {
                answer += (i + 1) * hands[i].second;
            }

            return answer;
        }
    }
}
