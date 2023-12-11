#include "not_enough_minerals.h"

using namespace notEnoughMinerals;

int solver() {
    int id = 1, answer = 0;

    while (!std::cin.eof()) {
        std::string line = utils::readLine();
        Blueprint blueprint = parseBlueprint(line);
        State state = State(0, 0, 0, 0, 1, 0, 0, 0);
        std::unordered_map<uint64_t , int> cache;
        int score = solve(state, blueprint, 24, cache);
        answer += score * id++;
    }
    return 10;
}

int notEnoughMinerals::firstPart() {
    return utils::solve(solver, input_file);
}