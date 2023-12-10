#include <iostream>

#include "2023/day_10/pipe_maze.h"


int main() {
    int64_t start = utils::currentTimeMillis();

    std::cout << pipeMaze::secondPart() << std::endl;
    std::cout << "Time: " << utils::currentTimeMillis() - start << " ms" << std::endl;
    return 0;
}
