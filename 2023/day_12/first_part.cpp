#include "hot_springs.h"

namespace hotSprings {
    class FirstPart : public HotSprings {
    public:
        FirstPart() : HotSprings() {}

        int countTotalCorrectArrangements() {
            int count = 0;
            for (std::string& line: lines) {
                auto [l, record] = parseLine(line);
                count += (int)countCorrectArrangements(l, record);
            }
            return count;
        }

        std::string solve() override {
            return std::to_string(countTotalCorrectArrangements());
        }
    };
}