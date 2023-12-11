#include <vector>
#include <unordered_map>
#include "gear_ratios.h"

namespace gearRatios {
    class SecondPart : public GearRatios {
    public:
        SecondPart() : GearRatios() {}

    private:
        void checkForSpecialCharacter(int i, int j, bool &marked) override {
            if (!utils::isOutOfBounds(i ,j, (int)lines.size(), (int)lines[i].size())) {
                marked |= isSpecialChar(lines[i][j]);
                if (lines[i][j] == '*') currentGears.emplace_back(i, j);
            }
        }

        void setup() override {
            currentGears.clear();
        }

        void update(int number, int &answer [[maybe_unused]]) override {
            for (auto gear: currentGears) {
                if (gears.find(gear) == gears.end()) {
                    gears[gear] = {number, -1};
                } else {
                    if (gears[gear].second == -1) gears[gear].second = number;
                    else gears[gear].first = -1;
                }
            }
        }

        void finalize(int &answer [[maybe_unused]]) override {
            for (auto gear: gears) {
                if (gear.second.first != -1 && gear.second.second != -1)
                    answer += gear.second.first * gear.second.second;
            }
        }

        std::vector<std::pair<int, int>> currentGears;
        std::unordered_map<std::pair<int, int>, std::pair<int, int>, utils::hash_pair<int, int>> gears;
    };
}
