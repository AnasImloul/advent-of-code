#include <vector>
#include "fertilizer.h"
#include <cstdint>

using namespace fertilizer;


ll processSeeds(std::vector<ll>& seeds, std::vector<Transformer>& transformers) {
    ll answer = INT64_MAX;
    for (int j = 0; j + 1 < seeds.size(); j += 2) {
        answer = std::min(answer, dfs({seeds[j], seeds[j] + seeds[j + 1] - 1}, transformers, 0));
    }
    return answer;
}

ll solver() {
    return fertilizer::solve(processSeeds);
}

ll fertilizer::secondPart() {
    return utils::solve<ll>(solver, input_file);
}