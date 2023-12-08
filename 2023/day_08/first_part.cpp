#include "haunted_wasteland.h"

using namespace hauntedWasteland;

ll solver() {
    auto [network, instructions] = readInput();
    std::string node = "AAA";
    return distance(node, network, instructions);
}

ll hauntedWasteland::firstPart() {
    return utils::solve(solver, input_file);
}