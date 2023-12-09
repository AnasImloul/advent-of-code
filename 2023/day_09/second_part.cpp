#include <algorithm>
#include "mirage_maintenance.h"

using namespace mirageMaintenance;

int solver() {
    std::vector<std::vector<int>> lines = readInput();

    int answer = 0;
    for (auto& line : lines) {
        std::reverse(line.begin(), line.end());
        answer += extrapolate(line, line.size());
        std::reverse(line.begin(), line.end());
    }
    return answer;
}

int mirageMaintenance::secondPart() {
    return utils::solve(solver, input_file);
}