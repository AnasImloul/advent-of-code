//
// Created by user on 03/12/2023.
//
#include <iostream>
#include <vector>
#include "camel_cards.h"
#include <cstdint>
#include <algorithm>
#include <array>


using namespace camelCards;

int cardToNumber(const char &c) {
    switch (c) {
        case '2': return 0; case '3': return 1; case '4': return 2;
        case '5': return 3; case '6': return 4; case '7': return 5;
        case '8': return 6; case '9': return 7; case 'T': return 8;
        case 'J': return 9; case 'Q': return 10; case 'K': return 11;
        case 'A': return 12;
    }
    return 0;
}

struct cmp {
    inline bool operator() (const std::pair<std::string, int>& hand1, const std::pair<std::string, int>& hand2) const {
        int score1 = getHandType(hand1.first);
        int score2 = getHandType(hand2.first);
        return calculateStrength(hand1.first, score1, cardToNumber) < calculateStrength(hand2.first, score2, cardToNumber);
    };
};


int solver() {
    std::vector<std::string> lines = utils::readLines();

    std::vector<std::pair<std::string, int>> hands;

    for (std::string& line : lines) {
        std::string hand = line.substr(0, 5);

        int i = 6;
        int bid = utils::nextInt(line, i);
        hands.emplace_back(hand, bid);
    }

    std::sort(hands.begin(), hands.end(), cmp());

    int answer = 0;
    for (int i = 0; i < hands.size(); i++) {
        answer += (i + 1) * hands[i].second;
    }

    return answer;
}

int camelCards::firstPart() {
    return utils::solve(solver, input_file);
}