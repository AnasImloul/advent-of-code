#include <iostream>
#include <chrono>
#include "2023/day_02/cube_conundrum.h"

int64_t time() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main() {
    std::cout << cubeConundrum::firstPart() << std::endl;
    return 0;
}
