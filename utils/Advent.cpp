#include "Advent.h"
#include "utils.h"

Advent::Advent(std::string &inputFile) : input_file(inputFile), in(inputFile) {
    // check if the file exists
    if (!in.good()) {
        std::cerr << "File " << input_file << " does not exist!" << std::endl;
        exit(1);
    }
}