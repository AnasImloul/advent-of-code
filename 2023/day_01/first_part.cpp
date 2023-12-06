//
// Created by user on 01/12/2023.
//



#include <string>
#include "trebuchet.h"
#include "../../utils.h"

using namespace trebuchet;


int parse(const std::string& line) {
    int left = -1, right = -1, i = 0;
    while (i < line.size()) {
        if (isdigit(line[i])) {
            if (left == -1) left = line[i] - '0';
            right = line[i] - '0';
        }
        i++;
    }
    return left * 10 + right;
}


int solve() {
    int answer = 0;
    std::string line;
    while (std::cin >> line) {
        answer += parse(line);
    }
    return answer;
}


int trebuchet::firstPart() {
    return utils::solve<int>(solve, input_file);
}