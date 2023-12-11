#include "cosmic_expansion.h"

using namespace cosmicExpansion;

class FirstPart : CosmicExpansion {
public:
    FirstPart() : CosmicExpansion() {}

    std::string solve() override {
        return std::to_string(calculatePairDistances(2));
    }
};