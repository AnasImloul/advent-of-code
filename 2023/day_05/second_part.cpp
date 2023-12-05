//
// Created by user on 03/12/2023.
//
#include <iostream>
#include <vector>
#include "fertilizer.h"
#include <cstdint>

using namespace fertilizer;


ll solver() {

    std::vector<std::string> lines = utils::readLines();
    int i = 0;

    std::vector<ll> seeds = utils::parseLongs(lines[i++]);

    std::vector<Transformer> transformers;
    transformers.reserve(7);

    for (int t = 0; t < 7; t++) {
        transformers.push_back(parseTransformer(lines, i));
    }

    ll answer = INT64_MAX;
    for (int j = 0; j + 1 < seeds.size(); j += 2) {
        answer = std::min(answer, dfs({seeds[j], seeds[j] + seeds[j + 1] - 1}, transformers, 0));
    }

    return answer;
}


ll fertilizer::secondPart() {
    return utils::solve<ll>(solver, input_file);
}