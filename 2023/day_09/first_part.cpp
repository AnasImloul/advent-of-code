#include "mirage_maintenance.h"

using namespace mirageMaintenance;

int solver() {
    std::vector<std::vector<int>> lines = readInput();

    int answer = 0;
    for (auto& line : lines) {
        answer += extrapolate(line, line.size());
    }

    return answer;
}

int mirageMaintenance::firstPart() {
    return utils::solve(solver, input_file);
}