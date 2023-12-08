#include "haunted_wasteland.h"

using namespace hauntedWasteland;

std::vector<std::string> extractStartingNodes(Network& network) {
    std::vector<std::string> nodes;
    for (auto& node: network) {
        if (node.first.back() == 'A') {
            nodes.push_back(node.first);
        }
    }
    return nodes;
}

ll solver() {
    return hauntedWasteland::solve(extractStartingNodes);
}

ll hauntedWasteland::secondPart() {
    return utils::solve(solver, input_file);
}