#include <iostream>

#include "2023/day_11/cosmic_expansion.h"


int main() {
    int64_t start = utils::currentTimeMicros();

    std::cout << cosmicExpansion::secondPart() << std::endl;
    std::cout << "Time: " << utils::currentTimeMicros() - start << " us" << std::endl;
    return 0;
}
