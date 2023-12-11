#include <iostream>

#include "2023/day_10/cosmic_expansion.h"


int main() {
    int64_t start = utils::currentTimeMillis();

    std::cout << pipeMaze::secondPart() << std::endl;
    std::cout << "Time: " << utils::currentTimeMillis() - start << " us" << std::endl;
    return 0;
}
