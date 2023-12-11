#include "cosmic_expansion.h"


namespace cosmicExpansion {
    class SecondPart : public CosmicExpansion {
    public:
        SecondPart() : CosmicExpansion() {}

        std::string solve() override {
            return std::to_string(calculatePairDistances(1'000'000));
        }
    };
}