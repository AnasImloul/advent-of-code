#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include "../../utils/utils.h"

enum MineralType {
    ORE = 0,
    CLAY = 1,
    OBSIDIAN = 2,
    GEODE = 3
};

struct State {
    State(uint8_t ore, uint8_t clay, uint8_t obsidian, uint8_t geode,
          uint8_t oreRobot, uint8_t clayRobot, uint8_t obsidianRobot, uint8_t geodeRobot):
            ore(ore), clay(clay), obsidian(obsidian), geode(geode),
            oreRobot(oreRobot), clayRobot(clayRobot), obsidianRobot(obsidianRobot), geodeRobot(geodeRobot) {}
    uint8_t ore;
    uint8_t clay;
    uint8_t obsidian;
    uint8_t geode;
    uint8_t oreRobot;
    uint8_t clayRobot;
    uint8_t obsidianRobot;
    uint8_t geodeRobot;
};

struct Mineral {
    Mineral(uint8_t ore = 0, uint8_t clay = 0, uint8_t obsidian = 0, uint8_t geode = 0):
            ore(ore), clay(clay), obsidian(obsidian), geode(geode) {}
    uint8_t ore;
    uint8_t clay;
    uint8_t obsidian;
    uint8_t geode;
};

namespace notEnoughMinerals {
    inline static std::string input_file = "../2022/day_19/in.txt";

    int firstPart();
    int secondPart();

    namespace {
        using Blueprint = std::array<Mineral, 4>;

        uint64_t hashcode(State& state) {
            return std::hash<uint64_t>()(
                    (uint64_t)state.ore << 56 |
                    (uint64_t)state.clay << 48 |
                    (uint64_t)state.obsidian << 40 |
                    (uint64_t)state.geode << 32 |
                    (uint64_t)state.oreRobot << 24 |
                    (uint64_t)state.clayRobot << 16 |
                    (uint64_t)state.obsidianRobot << 8 |
                    (uint64_t)state.geodeRobot
            );
        }

        Blueprint parseBlueprint(std::string& line) {
            Blueprint minerals;

            int i = 0;
            utils::skipUntil(line, i, [](char c){return c == ':';});

            for (int j = 0; j < 4; j++) {
                while (i < (int)line.size() && line[i] != '.') {
                    utils::skipUntil(line, i, utils::isdigit);
                    int amount = utils::nextInt(line, i);

                    utils::skipUntil(line, i, utils::isalpha);
                    std::string mineral = utils::readWhile(line, i, utils::isalpha);

                    if (mineral == "ore") minerals[j].ore = amount;
                    else if (mineral == "clay") minerals[j].clay = amount;
                    else if (mineral == "obsidian") minerals[j].obsidian = amount;
                    else if (mineral == "geode") minerals[j].geode = amount;
                }
                i++;
            }
            return minerals;
        }

        bool canBuild(State state, int type ,Blueprint blueprint) {
            return state.ore >= blueprint[type].ore &&
                   state.clay >= blueprint[type].clay &&
                   state.obsidian >= blueprint[type].obsidian &&
                   state.geode >= blueprint[type].geode;
        }

        void build(State& state, MineralType type, Blueprint blueprint) {
            state.ore -= blueprint[type].ore;
            state.clay -= blueprint[type].clay;
            state.obsidian -= blueprint[type].obsidian;
            state.geode -= blueprint[type].geode;

            switch(type) {
                case ORE: state.oreRobot++; break;
                case CLAY: state.clayRobot++; break;
                case OBSIDIAN: state.obsidianRobot++; break;
                case GEODE: state.geodeRobot++; break;
            }
        }

        int solve(State state, Blueprint blueprint, int timer, std::unordered_map<uint64_t, int>& cache) {
            if (timer == 0) return state.geode;

            uint64_t code = hashcode(state);

            if (cache.find(code) != cache.end()) return cache.at(code);

            int answer = 0;

            state.ore += state.oreRobot;
            state.clay += state.clayRobot;
            state.obsidian += state.obsidianRobot;
            state.geode += state.geodeRobot;

            for (int type = ORE; type <= GEODE; type++) {
                if (canBuild(state, type, blueprint)) {
                    State newState = state;
                    build(newState, static_cast<MineralType>(type), blueprint);
                    answer = std::max(answer, solve(newState, blueprint, timer - 1, cache));
                }
            }

            cache[code] = std::max(answer, solve(state, blueprint, timer - 1, cache));

            return cache[code];
        }
    }
}


// 1 2 3 5 9
// 1 1 2 4
// 0 1 2
// 1 1
// 0