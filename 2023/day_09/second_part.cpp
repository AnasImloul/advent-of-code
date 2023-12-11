#include <algorithm>
#include "mirage_maintenance.h"

namespace mirageMaintenance {
    class SecondPart : public MirageMaintenance {
        std::string solve() override {
            int answer = 0;
            for (auto& line : lines) {
                std::reverse(line.begin(), line.end());
                answer += extrapolate(line, (int)line.size());
                std::reverse(line.begin(), line.end());
            }
            return std::to_string(answer);
        }
    };
}