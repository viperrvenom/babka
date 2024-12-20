#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include "functions.hpp"

int countDistinctConsonants(const std::string& word) {
    std::set<char> consonants;
    for (char ch : word) {
        ch = tolower(ch);
        if (isalpha(ch) && !strchr("aeiou", ch)) {
            consonants.insert(ch);
        }
    }
    return consonants.size();
}

// 1
std::vector<std::pair<std::string, int>> findWordsWithMostConsonants(std::ifstream& inputFile) {
    std::map<std::string, int> wordCount;
    std::string word;

    while (inputFile >> word) {
        int count = countDistinctConsonants(word);
        if (count > 0) {
            wordCount[word] = count;
        }
    }

    std::vector<std::pair<std::string, int>> words(wordCount.begin(), wordCount.end());
    std::sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    if (words.size() > 2000) {
        words.resize(2000);
    }

    return words;
}

void writeWordsToFile(const std::vector<std::pair<std::string, int>>& words, const std::string& filename) {
    std::ofstream outputFile(filename);
    for (const auto& [word, count] : words) {
        outputFile << word << " (" << count << ")" << std::endl;
    }
}

// 2
std::vector<std::string> processWordsInText(const std::string& text) {
    std::istringstream stream(text);
    std::string word;
    std::vector<std::string> processedWords;

    while (stream >> word) {
        std::string vowels = "aeiou";
        bool hasRepeatedVowels = false;
        std::map<char, int> vowelCount;

        for (char ch : word) {
            if (strchr(vowels.c_str(), tolower(ch))) {
                vowelCount[tolower(ch)]++;
                if (vowelCount[tolower(ch)] > 1) {
                    hasRepeatedVowels = true;
                    break;
                }
            }
        }

        if (hasRepeatedVowels) {
            processedWords.push_back(word);
        } else {
            std::reverse(word.begin(), word.end());
            processedWords.push_back(word);
        }
    }

    std::sort(processedWords.begin(), processedWords.end());
    return processedWords;
}

void writeProcessedWordsToFile(const std::vector<std::string>& words, const std::string& filename) {
    std::ofstream outputFile(filename);
    for (const auto& word : words) {
        outputFile << word << std::endl;;
    }
}

// 3
std::string findWordsWithFrequentLetters(std::ifstream& inputFile) {
    std::map<char, int> letterFrequency;
    std::string text;
    std::string word;

    // frequency
    while (inputFile >> word) {
        for (char ch : word) {
            if (isalpha(ch)) {
                letterFrequency[tolower(ch)]++;
            }
        }
        text += word + " ";
    }

    // 8 most frequent letters
    std::vector<std::pair<char, int>> freqVec(letterFrequency.begin(), letterFrequency.end());
    std::sort(freqVec.begin(), freqVec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    std::set<char> frequentLetters;
    for (size_t i = 0; i < std::min(freqVec.size(), size_t(8)); ++i) {
        frequentLetters.insert(freqVec[i].first);
    }

    std::istringstream textStream(text);
    std::string outputText;
    while (textStream >> word) {
        std::set<char> foundLetters;
        for (char ch : word) {
            if (frequentLetters.count(tolower(ch))) {
                foundLetters.insert(tolower(ch));
            }
        }

        if (foundLetters.size() >= 5) {
            std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            outputText += word + " (" + std::string(foundLetters.begin(), foundLetters.end()) + ") ";
        } else {
            outputText += word + " ";
        }
    }

    return outputText;
}

void writeOutputToFile(const std::string& outputText, const std::string& filename) {
    std::ofstream outputFile(filename);
    outputFile << outputText;
}