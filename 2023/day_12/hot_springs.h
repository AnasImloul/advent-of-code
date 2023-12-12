#pragma once

#include <vector>
#include "../../utils/utils.h"
#include "../../utils/Advent.h"


namespace hotSprings {
    class HotSprings : public Advent {

    protected:
        HotSprings() : Advent(input_file) {
            lines = utils::readLines(in);
        }

        static ll countCorrectArrangements(const std::string& line, const std::vector<int>& record) {
            std::vector<std::vector<ll>> cache(line.size(), std::vector<ll>(record.size(), -1));
            ll result = 0;
            for (int i = 0; i < (int)line.size(); i++) {
                if (line[i] == OPERATIONAL) continue;
                result += countCorrectArrangementsHelper(line, record, cache, i, 0);
                if (line[i] == DAMAGED) break;
            }
            return result;
        }

        static ll countCorrectArrangementsHelper(
                const std::string& line,
                const std::vector<int>& record,
                std::vector<std::vector<ll>>& cache,
                int i, int j) {

            int _i = i, _j = j;

            if (cache[_i][_j] != -1) return cache[_i][_j];

            int k = record[j];
            while (k > 0 && i < (int)line.size() && line[i] != OPERATIONAL) {
                i++, k--;
            }

            if (k != 0 || (i < (int)line.size() && line[i] == DAMAGED)) {
                return cache[_i][_j] = 0;
            }

            if (j + 1 == (int)record.size()) {
                while (i < (int)line.size() && line[i] != DAMAGED) {
                    i++;
                }
                if (i == (int)line.size()) return cache[_i][_j] = 1;
                else return cache[_i][_j] = 0;
            }

            ll result = 0;
            for (int l = i + 1; l < (int)line.size(); l++) {
                if (line[l] == OPERATIONAL) continue;
                result += countCorrectArrangementsHelper(line, record, cache, l, j + 1);
                if (line[l] == DAMAGED) break;
            }

            return cache[_i][_j] = result;
        }

        static std::pair<std::string, std::vector<int>> parseLine(const std::string& line) {
            int i = 0;
            std::string l = utils::readUntil(line, i, utils::isspace);
            utils::skipUntil(line, i, utils::isdigit);
            std::vector<int> record = utils::parseIntegers(line, i);
            return {l, record};
        }

        inline static std::string input_file = "../2023/day_12/in.txt";
        static const char UNKNOWN = '?';
        static const char DAMAGED = '#';
        static const char OPERATIONAL = '.';

        std::vector<std::string> lines;
    };
}