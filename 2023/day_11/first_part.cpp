#include "cosmic_expansion.h"

namespace cosmicExpansion {
    class FirstPart : public CosmicExpansion {
    public:
        FirstPart() : CosmicExpansion() {}

        std::string solve() override {
            return std::to_string(calculatePairDistances(2));
        }
    };
}