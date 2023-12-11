#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class Advent {
public:
    Advent(std::string &inputFile);
    virtual std::string solve() = 0;

private:
    std::string& input_file;

protected:
    std::ifstream in;
};
