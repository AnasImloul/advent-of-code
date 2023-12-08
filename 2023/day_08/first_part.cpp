#include "haunted_wasteland.h"


using namespace hauntedWasteland;

std::vector<std::string> extractStartingNodes(Network& network) {
    return {"AAA"};
}

ll solver() {
    return hauntedWasteland::solve(extractStartingNodes);
}

ll hauntedWasteland::firstPart() {
    return utils::solve(solver, input_file);
}