#include <vector>
#include "fertilizer.h"
#include <cstdint>

using namespace fertilizer;

ll processSeeds(std::vector<ll>& seeds, std::vector<Transformer>& transformers) {
    ll answer = INT64_MAX;
    for (auto& seed : seeds) {
        answer = std::min(answer, dfs({seed, seed}, transformers, 0));
    }
    return answer;
}

ll solver() {
    return fertilizer::solve(processSeeds);
}

ll fertilizer::firstPart() {
    return utils::solve(solver, input_file);
}