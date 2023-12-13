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
            std::vector<int> operationalPrefix(line.size() + 1, 0);
            for (int i = 0; i < (int)line.size(); i++) {
                operationalPrefix[i + 1] = operationalPrefix[i] + (line[i] == OPERATIONAL ? 1 : 0);
            }

            std::vector<std::vector<ll>> cache(line.size() + 1, std::vector<ll>(record.size() + 1, 0));

            cache[line.size()][record.size()] = 1;
            for (int i = (int)line.size() - 1; i >= 0; i--) {
                if (line[i] == DAMAGED) break;
                cache[i][record.size()] = 1;
            }

            for (int i = (int)line.size() - 1; i >= 0; i--) {
                for (int j = (int)record.size() - 1; j >= 0; j--) {
                    cache[i][j] = 0;
                    if (line[i] != DAMAGED) cache[i][j] += cache[i + 1][j];
                    if (i + record[j] <= (int)line.size() && operationalPrefix[i + record[j]] - operationalPrefix[i] == 0) {
                        if (i + record[j] == (int)line.size()) cache[i][j] += cache[i + record[j]][j + 1];
                        else if (line[i + record[j]] != DAMAGED) cache[i][j] += cache[i + record[j] + 1][j + 1];
                    }
                }
            }
            return cache[0][0];
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