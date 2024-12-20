#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

namespace MatrixOperations
{
    void readMatrix(std::vector<std::vector<int>>& matrix, int& n);
    void processMatrix(std::vector<std::vector<int>>& matrix, int n);
    void writeMatrix(const std::vector<std::vector<int>>& matrix, int n);
    bool isPrime(int number);
}

#endif
