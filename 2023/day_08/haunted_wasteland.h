#pragma once

#include <vector>
#include <unordered_map>
#include <array>
#include "../../utils/utils.h"

namespace hauntedWasteland {
    inline static std::string input_file = "../2023/day_08/in.txt";

    ll firstPart();
    ll secondPart();

    namespace {
        using Network = std::unordered_map<std::string, std::pair<std::string, std::string>>;

        std::array<std::string, 3> parseNode(std::string& line) {
            std::array<std::string, 3> result;
            int i = 0;
            for (int j = 0; j < 3; j++) {
                utils::skipUntil(line, i, utils::isalnum);
                result[j] = utils::readWhile(line, i, utils::isalnum);
            }
            return result;
        }

        ll distance(std::string& node, Network& network, std::string& instructions) {
            ll distance = 0;
            while (node.back() != 'Z') {
                if (instructions[distance % instructions.size()] == 'L') {
                    node = network[node].first;
                } else {
                    node = network[node].second;
                }
                distance++;
            }
            return distance;
        }

        std::pair<Network, std::string> readInput() {
            std::string instructions = utils::readLine();
            utils::readLine();

            Network network;
            while (!std::cin.eof()) {
                std::string line = utils::readLine();
                auto [node, left, right] = parseNode(line);
                network[node] = {left, right};
            }

            return {network, instructions};
        }
    }
}