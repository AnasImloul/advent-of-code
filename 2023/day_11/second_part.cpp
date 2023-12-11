#include "cosmic_expansion.h"

using namespace cosmicExpansion;

ll solver() {
    return solve(1'000'000);
}

ll cosmicExpansion::secondPart() {
    return utils::solve(solver, input_file);
}