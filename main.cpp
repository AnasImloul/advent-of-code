#include <iostream>

#include "2023/day_11/cosmic_expansion.h"
#include "2023/day_11/second_part.cpp"



int main() {
    int64_t start = utils::currentTimeMicros();

    std::cout << SecondPart().solve() << std::endl;
    std::cout << "Time: " << utils::currentTimeMicros() - start << " us" << std::endl;
    return 0;
}
