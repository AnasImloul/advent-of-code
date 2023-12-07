#include <string>
#include "trebuchet.h"

using namespace trebuchet;

int digitChecker(const std::string& line, int i) {
    return (isdigit(line[i]) ? line[i] - '0' : -1);
}

int trebuchet::firstPart() {
    return utils::solve<int>([](){return solve(digitChecker);}, input_file);
}