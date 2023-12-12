#include <iostream>
#include "2023/day_12/first_part.cpp"
#include "2023/day_12/second_part.cpp"


int main() {
    // utils::fastIO();

    int64_t start = utils::currentTimeMicros();

    Advent *firstPart = new hotSprings::FirstPart();
    Advent *secondPart = new hotSprings::SecondPart();

    std::cout << firstPart->solve() << std::endl;
    std::cout << secondPart->solve() << std::endl;
    std::cout << "Time: " << utils::currentTimeMicros() - start << " us" << std::endl;
    return 0;
}
