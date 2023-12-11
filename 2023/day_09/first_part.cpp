#include "mirage_maintenance.h"

namespace mirageMaintenance {
    class FirstPart : public MirageMaintenance {
        std::string solve() override {
            int answer = 0;
            for (auto& line : lines) {
                answer += extrapolate(line, (int)line.size());
            }
            return std::to_string(answer);
        }
    };
}