#include <iostream>
#include <fstream>
#include <vector>
#include "longest_path.h"

int main() {
    std::ifstream file("file_paths.txt");  
    std::string line;
    std::vector<std::pair<int, std::string>> intermediateResults;

    // Step 1: Map phase - Process each line in the file
    while (std::getline(file, line)) {
        auto mapped = Mapper::map(line);  // Mapper processes each path
        intermediateResults.insert(intermediateResults.end(), mapped.begin(), mapped.end());
    }

    // Step 2: Reduce phase - Find the longest path(s)
    Reducer::reduce(intermediateResults);  // Reducer processes the intermediate results

    return 0;
}
