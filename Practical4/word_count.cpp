#include "word_count.h"

// Mapper: Tokenizes the line and returns key-value pairs (word, 1)
std::vector<std::pair<std::string, int>> Mapper::map(const std::string& line) {
    std::vector<std::pair<std::string, int>> keyValuePairs;
    std::istringstream stream(line);
    std::string word;

    while (stream >> word) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);  // Normalize to lowercase
        keyValuePairs.push_back(std::make_pair(word, 1));
    }

    return keyValuePairs;
}

// Reducer: Aggregates word counts
void Reducer::reduce(const std::vector<std::pair<std::string, int>>& intermediate) {
    std::map<std::string, int> wordCountMap;

    // Aggregate counts by word
    for (const auto& pair : intermediate) {
        wordCountMap[pair.first] += pair.second;
    }

    // Output word counts
    for (const auto& entry : wordCountMap) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}
