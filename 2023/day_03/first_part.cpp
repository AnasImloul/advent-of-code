#include <iostream>
#include <vector>
#include "gear_ratios.h"
#include "../../utils/utils.h"

namespace gearRatios {
    class FirstPart : public GearRatios {
    public:
        FirstPart() : GearRatios() {}

    private:
        void checkForSpecialCharacter(int i, int j, bool &marked) override {
            if (!utils::isOutOfBounds(i, j, (int) lines.size(), (int) lines[i].size())) {
                marked |= isSpecialChar(lines[i][j]);
            }
        }

        void setup() override {}

        void update(int number, int &answer) override { answer += number; }

        void finalize(int &answer [[maybe_unused]]) override {}
    };
}