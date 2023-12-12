#include "hot_springs.h"

namespace hotSprings {
    class SecondPart : public HotSprings {
    public:
        SecondPart() : HotSprings() {}


        ll countTotalCorrectArrangements() {
            ll count = 0;
            for (std::string& line: lines) {
                auto [l1, record1] = parseLine(line);
                auto [l2, record2] = unwrap(l1, record1);
                count += countCorrectArrangements(l2, record2);

            }
            return count;
        }

        std::string solve() override {
            return std::to_string(countTotalCorrectArrangements());
        }

        static std::pair<std::string, std::vector<int>> unwrap(std::string& line, std::vector<int>& record) {
            std::string unwrapped = line;
            std::vector<int> record1 = std::vector<int>(record);
            for (int i = 0; i < 4; i++) {
                for (auto &num: record) record1.push_back(num);
                unwrapped.append( "?" + line);
            }
            return {unwrapped, record1};
        }
    };
}