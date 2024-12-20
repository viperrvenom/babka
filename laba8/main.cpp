#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.hpp"

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    // 1
    std::vector<std::pair<std::string, int>> wordsWithConsonants = findWordsWithMostConsonants(inputFile);
    writeWordsToFile(wordsWithConsonants, "output1.txt");

    inputFile.clear();
    inputFile.seekg(0, std::ios::beg); // Сбросить указатель файла

    // 2
    std::string text;
    std::getline(inputFile, text, '\0'); // Чтение всего текста
    std::vector<std::string> processedWords = processWordsInText(text);
    writeProcessedWordsToFile(processedWords, "output2.txt");

    // 3
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
    std::string outputText = findWordsWithFrequentLetters(inputFile);
    writeOutputToFile(outputText, "output3.txt");

    inputFile.close();
    return 0;
}