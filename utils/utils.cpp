#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "utils.h"


namespace utils {

    void skipUntil(const std::string &str, int &i, Condition<char> *condition) {
        while (i < str.size() && !condition(str[i])) {
            i++;
        }
    }

    std::string readUntil(const std::string &str, int &i, Condition<char> *condition) {
        int j = i;
        while (i < str.size() && !condition(str[i])) {
            i++;
        }
        return str.substr(j, i - j);
    }

    void skipWhile(const std::string &str, int &i, Condition<char> *condition) {
        while (i < str.size() && condition(str[i])) {
            i++;
        }
    }

    std::string readWhile(const std::string &str, int &i, Condition<char> *condition) {
        int j = i;
        while (i < str.size() && condition(str[i])) {
            i++;
        }
        return str.substr(j, i - j);
    }

    int nextInt(const std::string &str, int &i) {
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        int number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return sign * number;
    }

    long long nextLong(const std::string &str, int &i) {
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        long long number = 0;
        while (i < str.size() && isdigit(str[i])) {
            number = number * 10 + (str[i] - '0');
            i++;
        }
        return sign * number;
    }

    std::vector<int> parseIntegers(std::string &line) {
        std::vector<int> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c) || c == '-' || c == '+'; });
            int number = nextInt(line, i);
            numbers.push_back(number);
        }
        return numbers;
    }

    std::vector<long long> parseLongs(std::string &line) {
        std::vector<long long> numbers;

        int i = 0;
        while (i < line.size()) {
            skipUntil(line, i, [](char c) { return (bool) isdigit(c) || c == '-' || c == '+'; });
            long long number = nextLong(line, i);
            numbers.push_back(number);
        }

        return numbers;
    }

    std::vector<std::string> readLines() {
        std::vector<std::string> lines;
        while (!std::cin.eof()) {
            lines.push_back(readLine());
        }
        return lines;
    }

    std::string readLine() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    bool isOutOfBounds(int i, int j, int n, int m) {
        return i < 0 | i >= n | j < 0 | j >= m;
    }

    bool areParallel(const std::pair<int, int>& a, const std::pair<int, int>& b, const std::pair<int, int>& c) {
        return (b.first - a.first) * (c.second - a.second) == (c.first - a.first) * (b.second - a.second);
    }

    std::vector<std::pair<int ,int>> reducePolygon(const std::vector<std::pair<int, int>>& polygon) {
        if (polygon.size() < 3) return polygon;

        std::vector<std::pair<int, int>> reduced;
        reduced.push_back(polygon[0]);
        reduced.push_back(polygon[1]);

        for (int i = 2; i < polygon.size(); i++) {
            if (areParallel(polygon[i], reduced[reduced.size() - 2], reduced[reduced.size() - 1])) {
                reduced.pop_back();
            }
            reduced.push_back(polygon[i]);
        }

        return reduced;
    }

    bool isPointInsidePolygon(int x, int y, const std::vector<std::pair<int, int>>& polygon) {
        int n = polygon.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int x1 = polygon[i].first;
            int y1 = polygon[i].second;
            int x2 = polygon[(i + 1) % n].first;
            int y2 = polygon[(i + 1) % n].second;

            if ((y1 <= y && y < y2) || (y2 <= y && y < y1)) {
                if (x1 + (y - y1) / static_cast<double>(y2 - y1) * (x2 - x1) < x) {
                    count++;
                }
            }
        }

        return count % 2 == 1;
    }

    int64_t currentTimeMillis() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }

    int64_t currentTimeMicros() {
        using namespace std::chrono;
        return duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }

    int64_t currentTimeNanos() {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
    }
}