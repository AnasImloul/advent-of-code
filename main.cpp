#include <iostream>

#include "2023/day_11/second_part.cpp"



int main() {
    int64_t start = utils::currentTimeMicros();

    Advent *advent = new cosmicExpansion::SecondPart();

    std::cout << advent->solve() << std::endl;
    std::cout << "Time: " << utils::currentTimeMicros() - start << " us" << std::endl;
    return 0;
}
