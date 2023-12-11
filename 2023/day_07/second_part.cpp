#include <iostream>
#include <vector>
#include "camel_cards.h"
#include <algorithm>
#include <array>

using namespace camelCards;

static std::string cards = "J23456789TQKA";

void replace(const std::string &hand, std::string &newHand, char oldChar, char newChar) {
    for (int i = 0; i < (int)hand.size(); i++) {
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
    inline bool operator() (const BiddingHand& hand1, const BiddingHand& hand2) const {
        int score1 = getJokerHandType(hand1.first);
        int score2 = getJokerHandType(hand2.first);
        return calculateStrength(hand1.first, score1, cards) < calculateStrength(hand2.first, score2, cards);
    };
};

void sortingAlgorithm(std::vector<BiddingHand>& hands) {
    std::sort(hands.begin(), hands.end(), cmp());
}

int solver() {
    return solve(sortingAlgorithm);
}

int camelCards::secondPart() {
    return utils::solve(solver, input_file);
}