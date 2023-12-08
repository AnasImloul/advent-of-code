#include <numeric>
#include "haunted_wasteland.h"

using namespace hauntedWasteland;

std::vector<std::string> getStartingNodes(Network& network) {
    std::vector<std::string> nodes;
    for (auto& node: network) {
        if (node.first.back() == 'A') {
            nodes.push_back(node.first);
        }
    }
    return nodes;
}

ll solver() {
    auto [network, instructions] = readInput();
    ll answer = 1;
    for (std::string& node: getStartingNodes(network)) {
        answer = std::lcm(answer, distance(node, network, instructions));
    }
    return answer;
}

ll hauntedWasteland::secondPart() {
    return utils::solve(solver, input_file);
}