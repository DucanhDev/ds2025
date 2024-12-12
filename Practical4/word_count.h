#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

// Mapper class
class Mapper {
public:
    static std::vector<std::pair<std::string, int>> map(const std::string& line);
};

// Reducer class
class Reducer {
public:
    static void reduce(const std::vector<std::pair<std::string, int>>& intermediate);
};

#endif
