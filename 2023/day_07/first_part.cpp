#include <iostream>
#include <vector>
#include "camel_cards.h"
#include <algorithm>
#include <array>

using namespace camelCards;

static std::string cards = "23456789TJQKA";

struct cmp {
    inline bool operator() (const BiddingHand& hand1, const BiddingHand& hand2) const {
        int score1 = getHandType(hand1.first);
        int score2 = getHandType(hand2.first);
        return calculateStrength(hand1.first, score1, cards) < calculateStrength(hand2.first, score2, cards);
    };
};

void sortingAlgorithm(std::vector<BiddingHand>& hands) {
    std::sort(hands.begin(), hands.end(), cmp());
}

int solver() {
    return solve(sortingAlgorithm);
}

int camelCards::firstPart() {
    return utils::solve(solver, input_file);
}