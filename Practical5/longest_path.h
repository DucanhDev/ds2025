#ifndef LONGEST_PATH_H
#define LONGEST_PATH_H

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
    static std::vector<std::pair<int, std::string>> map(const std::string& path);
};

// Reducer class
class Reducer {
public:
    static void reduce(const std::vector<std::pair<int, std::string>>& intermediate);
};

#endif
