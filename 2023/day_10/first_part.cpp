#include "pipe_maze.h"

namespace pipeMaze {
    class FirstPart : public PipeMaze {

        std::string solve() override {
            return std::to_string(getLoopElements().size() / 2);
        }

    public:
        FirstPart() : PipeMaze() {}
    };
}