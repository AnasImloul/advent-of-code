#include <string>
#include "trebuchet.h"

using namespace trebuchet;

std::string digits[9] = {
    "one","two", "three",
    "four", "five", "six",
    "seven", "eight", "nine"
};

int longestPrefix(const std::string& line, const std::string& substring, int start) {
    int j = 0;
    while (j < substring.size() && start + j < line.size() && substring[j] == line[start + j]) {
        j++;
    }
    return j;
}

int digitChecker(const std::string& line, int i) {
    if (isdigit(line[i])) return line[i] - '0';
    for (int d = 1; d <= 9; d++) {
        int j = longestPrefix(line, digits[d - 1], i);
        if (j == digits[d - 1].size()) return d;
    }
    return -1;
}

int trebuchet::secondPart() {
    return utils::solve<int>([](){return solve(digitChecker);}, input_file);
}