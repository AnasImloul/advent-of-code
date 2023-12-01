//
// Created by user on 01/12/2023.
//

#pragma once

#include <string>
#include "trebuchet.h"

namespace {
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
}

int trebuchet::firstPart() {
    return trebuchet::solve(parse);
}