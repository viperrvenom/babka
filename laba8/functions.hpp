#pragma_once

#include <vector>
#include <string>

std::vector<std::pair<std::string, int>> findWordsWithMostConsonants(std::ifstream& inputFile);
void writeWordsToFile(const std::vector<std::pair<std::string, int>>& words, const std::string& filename);

std::vector<std::string> processWordsInText(const std::string& text);
void writeProcessedWordsToFile(const std::vector<std::string>& words, const std::string& filename);

std::string findWordsWithFrequentLetters(std::ifstream& inputFile);
void writeOutputToFile(const std::string& outputText, const std::string& filename);

#endif // FUNCTIONS_HPP
