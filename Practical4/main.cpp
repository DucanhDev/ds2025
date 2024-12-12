#include <iostream>
#include <fstream>
#include <vector>
#include "word_count.h"

int main() {
    std::ifstream file("input.txt");  // Assuming input.txt contains the text for word counting
    std::string line;
    std::vector<std::pair<std::string, int>> intermediateResults;

    // Step 1: Map phase
    while (std::getline(file, line)) {
        auto mapped = Mapper::map(line);  // Mapper processes each line
        intermediateResults.insert(intermediateResults.end(), mapped.begin(), mapped.end());
    }

    // Step 2: Reduce phase
    Reducer::reduce(intermediateResults);  // Reducer aggregates and outputs word counts

    return 0;
}
