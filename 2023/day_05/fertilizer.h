#pragma once

#include <vector>
#include <map>
#include "../../utils/utils.h"


namespace fertilizer {
    inline static std::string input_file = "../2023/day_05/in.txt";

    ll firstPart();
    ll secondPart();
    namespace {
        using Transformer = std::map<std::pair<ll, ll>, std::pair<ll, ll>>;
        using SeedProcessor = ll(std::vector<ll>&, std::vector<Transformer>&);

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

            auto it = transformer.begin();

            while (it != transformer.end()) {
                auto [source, destination] = *it;
                if (source.first > start) {
                    if (source.first > end) {
                        intervals.emplace_back(start, end);
                        start = end + 1;
                        break;
                    }
                    intervals.emplace_back(start, source.first - 1);
                    start = source.first;
                    continue;
                }

                if (source.second >= start) {
                    if (source.second >= end) {
                        intervals.emplace_back(map({start, end}, source, destination));
                        start = end + 1;
                        break;
                    }
                    intervals.emplace_back(map({start, source.second}, source, destination));
                    start = source.second + 1;
                }
                it++;
            }

            if (start <= end) intervals.emplace_back(start, end);

            return intervals;
        }

        ll dfs(std::pair<ll, ll> interval, std::vector<Transformer>& transformers, int i) {
            if (i == 7) return interval.first;

            ll result = INT64_MAX;
            for (auto _interval : transform(interval, transformers[i])) {
                result = std::min(result, dfs(_interval, transformers, i + 1));
            }

            return result;
        }

        ll solve(SeedProcessor processSeeds) {
            std::vector<std::string> lines = utils::readLines();
            int i = 0;

            std::vector<ll> seeds = utils::parseLongs(lines[i++]);

            std::vector<Transformer> transformers(7);

            for (int t = 0; t < 7; t++) {
                transformers[t] = parseTransformer(lines, i);
            }

            return processSeeds(seeds, transformers);
        }
    }
}
