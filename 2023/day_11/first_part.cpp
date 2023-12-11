#include "cosmic_expansion.h"

using namespace cosmicExpansion;

ll solver() {
    return solve(2ll);
}

ll cosmicExpansion::firstPart() {
    return utils::solve(solver, input_file);
}