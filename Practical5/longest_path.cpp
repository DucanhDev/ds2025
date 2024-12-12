#include "longest_path.h"

// Mapper: Calculates the number of directories in the path
std::vector<std::pair<int, std::string>> Mapper::map(const std::string& path) {
    std::vector<std::pair<int, std::string>> keyValuePairs;
    std::stringstream ss(path);
    std::string directory;
    int count = 0;

    while (std::getline(ss, directory, '/')) {
        if (!directory.empty()) {
            count++;
        }
    }

    keyValuePairs.push_back(std::make_pair(count, path));
    return keyValuePairs;
}

// Reducer: Finds the longest path
void Reducer::reduce(const std::vector<std::pair<int, std::string>>& intermediate) {
    int maxLength = 0;  
    std::vector<std::string> longestPaths; 

    for (const auto& pair : intermediate) {
        if (pair.first > maxLength) {
            maxLength = pair.first; 
            longestPaths.clear(); 
            longestPaths.push_back(pair.second); 
        } else if (pair.first == maxLength) {
            longestPaths.push_back(pair.second);  
        }
    }
    if (longestPaths.size() == 1) {
        std::cout << "Longest Path: " << longestPaths[0] << std::endl;
    } else {
        for (const auto& path : longestPaths) {
            std::cout << "Longest Path: " << path << std::endl;
        }
    }
}

