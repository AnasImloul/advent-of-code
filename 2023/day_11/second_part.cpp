#include "cosmic_expansion.h"

using namespace cosmicExpansion;

class SecondPart : CosmicExpansion {

public:
    SecondPart() : CosmicExpansion() {}

    std::string solve() override {
        return std::to_string(calculatePairDistances(1'000'000));
    }
};