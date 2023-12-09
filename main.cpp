#include <iostream>

#include "2023/day_09/mirage_maintenance.h"



int main() {
    int64_t start = utils::currentTimeMillis();

    std::cout << mirageMaintenance::secondPart() << std::endl;
    std::cout << "Time: " << utils::currentTimeMillis() - start << " ms" << std::endl;
    return 0;
}
