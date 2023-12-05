//
// Created by user on 03/12/2023.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <map>
#include "../../utils.h"



namespace fertilizer {
    int firstPart();
    int secondPart();
    namespace {
        using Solver = int();
        int solve(Solver solver) {
            std::streambuf *oldCin = std::cin.rdbuf();
            std::ifstream in("../2023/day_05/in.txt");
            std::cin.rdbuf(in.rdbuf());

            int answer = solver();

            std::cin.rdbuf(oldCin);
            return answer;
        }

        using Transformer = std::map<std::pair<ll, ll>, std::pair<ll, ll>>;

        Transformer parseTransformer(std::vector<std::string>& lines, int& i) {
            while (lines[i].empty() || !isdigit(lines[i][0])) {
                i++;
            }

            Transformer transformer;

            while (!lines[i].empty() && isdigit(lines[i][0])) {
                std::vector<ll> intervals = utils::parseLongs(lines[i]);
                transformer[{intervals[1], intervals[1] + intervals[2] - 1}] = {intervals[0], intervals[0] + intervals[2] - 1};
                i++;
            }

            return transformer;
        }

        std::pair<ll, ll> map(std::pair<ll, ll> interval, const std::pair<ll, ll>& source, const std::pair<ll, ll>& destination) {
            auto [start, end] = interval;
            auto [sourceStart, sourceEnd] = source;
            auto [destinationStart, destinationEnd] = destination;

            // interval is contained in source
            return {destinationStart + (start - sourceStart), destinationStart + (end - sourceStart)};
        }

        std::vector<std::pair<ll, ll>> transform(std::pair<ll, ll> interval, Transformer& transformer) {
            std::vector<std::pair<ll, ll>> intervals;

            auto [start, end] = interval;

            for (auto it = transformer.begin(); it != transformer.end(); it++) {
                auto [source, destination] = *it;

                if (source.first > start) {
                    if (source.first > end) {
                        intervals.emplace_back(start, end);
                        break;
                    } else {
                        intervals.emplace_back(start, source.first - 1);
                        start = source.first;
                    }

                    if (source.second > end) {
                        intervals.emplace_back(map({start, end}, source, destination));
                        return intervals;
                    } else {
                        intervals.emplace_back(map({start, source.second}, source, destination));
                        start = source.second + 1;
                    }
                } else {
                    if (source.second < start) continue;
                    if (source.second > end) {
                        intervals.emplace_back(map({start, end}, source, destination));
                        return intervals;
                    } else {
                        intervals.emplace_back(map({start, source.second}, source, destination));
                        start = source.second + 1;
                    }
                }
            }

            intervals.emplace_back(start, end);

            return intervals;
        }
    }
}
