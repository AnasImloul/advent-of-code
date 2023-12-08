#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cstdint>
#include <array>
#include <numeric>
#include "../../utils/utils.h"


namespace hauntedWasteland {
    inline static std::string input_file = "../2023/day_08/in.txt";

    ll firstPart();
    ll secondPart();

    namespace {
        using Network = std::unordered_map<std::string, std::pair<std::string, std::string>>;
        using StartingNodesExtractor = std::vector<std::string>(Network&);
        std::array<std::string, 3> parseNode(std::string& line) {

            std::array<std::string, 3> result;

            int i = 0;
            for (int j = 0; j < 3; j++) {
                utils::skipUntil(line, i, utils::isalnum);
                result[j] = utils::readWhile(line, i, utils::isalnum);
            }

            return result;
        }

        Network parseNetwork(std::vector<std::string>& lines) {
            Network network;
            for (std::string& line: lines) {
                auto [node, left, right] = parseNode(line);
                network[node] = {left, right};
            }
            return network;
        }

        std::pair<std::string, Network> readInput() {
            std::string instructions = utils::readLine();

            utils::readLine();

            std::vector<std::string> lines = utils::readLines();
            Network network = parseNetwork(lines);

            return {instructions, network};
        }

        ll solve(StartingNodesExtractor extractStartingNodes) {
            auto [instructions, network] = readInput();

            std::vector<std::string> nodes = extractStartingNodes(network);

            ll answer = 1;
            for (auto& node : nodes) {
                std::string current = node;
                ll step = 0;
                do {
                    if (instructions[step % instructions.size()] == 'L') {
                        current = network[current].first;
                    } else {
                        current = network[current].second;
                    }
                    step++;
                } while (current.back() != 'Z');

                answer = std::lcm(answer, step);
            }

            return answer;
        }
    }
}
