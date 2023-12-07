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

static std::string cards = "23456789TJQKA";

int cardToNumber(const char &c) {
    switch (c) {
        case 'J': return 0; case '2': return 1; case '3': return 2;
        case '4': return 3; case '5': return 4; case '6': return 5;
        case '7': return 6; case '8': return 7; case '9': return 8;
        case 'T': return 9; case 'Q': return 10; case 'K': return 11;
        case 'A': return 12;
    }
    return 0;
}

void replace(const std::string &hand, std::string &newHand, char oldChar, char newChar) {
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == oldChar) newHand[i] = newChar;
        else newHand[i] = hand[i];
    }
}

int getJokerHandType(const std::string& hand) {
    int score = getHandType(hand);
    std::string newHand(hand.size(), '0');
    for (char& card: cards) {
        replace(hand, newHand, 'J', card);
        score = std::max(score, getHandType(newHand));
    }
    return score;
}

struct cmp {
    inline bool operator() (const std::pair<std::string, int>& hand1, const std::pair<std::string, int>& hand2) const {
        int score1 = getJokerHandType(hand1.first);
        int score2 = getJokerHandType(hand2.first);
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

int camelCards::secondPart() {
    return utils::solve(solver, input_file);
}