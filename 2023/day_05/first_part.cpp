//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <vector>
#include "fertilizer.h"
#include <cstring>
#include <cstdint>

using namespace fertilizer;



ll dfs(std::pair<ll, ll> interval, std::vector<Transformer>& transformers, int i) {
    if (i == 7) {
        return interval.first;
    }

    ll result = INT64_MAX;
    for (auto _interval : transform(interval, transformers[i])) {
        result = std::min(result, dfs(_interval, transformers, i + 1));
    }

    return result;
}


int solver() {

    std::vector<std::string> lines = utils::readLines();
    int i = 0;

    std::vector<ll> seeds = utils::parseLongs(lines[i++]);

    std::vector<Transformer> transformers;
    transformers.reserve(7);

    for (int t = 0; t < 7; t++) {
        transformers.push_back(parseTransformer(lines, i));
    }

    ll answer = INT64_MAX;
    for (auto& seed : seeds) {
        answer = std::min(answer, dfs({seed, seed}, transformers, 0));
    }

    return answer;
}


int fertilizer::firstPart() {
    return fertilizer::solve(solver);
}

