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

            if (cache[i][j] != -1) return cache[i][j];

            int k = i;
            for (int _ = 0; _ < record[j]; _++) {
                if (line[k] == OPERATIONAL) return cache[i][j] = 0;
                if (k == (int)line.size()) return cache[i][j] = 0;
                k++;
            }

            if (k < (int)line.size() && line[k] == DAMAGED)
                return cache[i][j] = 0;

            if (j + 1 == (int)record.size()) {
                while (k < (int)line.size() && line[k] != DAMAGED) {
                    k++;
                }
                return cache[i][j] = (k == (int)line.size() ? 1 : 0);
            }

            ll result = 0;
            for (int l = k + 1; l < (int)line.size(); l++) {
                if (line[l] == OPERATIONAL) continue;
                result += countCorrectArrangementsHelper(line, record, cache, l, j + 1);
                if (line[l] == DAMAGED) break;
            }

            return cache[i][j] = result;
        }

        static std::pair<std::string, std::vector<int>> parseLine(const std::string& line) {
            int i = 0;
            std::string l = utils::readUntil(line, i, utils::isspace);
            utils::skipUntil(line, i, utils::isdigit);
            std::vector<int> record = utils::parseIntegers(line, i);
            return {l, record};
        }

        inline static std::string input_file = "../2023/day_12/in.txt";
        static const char DAMAGED = '#';
        static const char OPERATIONAL = '.';

        std::vector<std::string> lines;
    };
}