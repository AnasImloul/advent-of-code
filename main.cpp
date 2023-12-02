#include <iostream>
#include <chrono>
#include "2023/day_02/cube_conundrum.h"

int64_t time() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main() {
    int64_t start = time();
    std::cout << cubeConundrum::firstPart() << std::endl;
    std::cout << time() - start << "ms" << std::endl;
    return 0;
}
