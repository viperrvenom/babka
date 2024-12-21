#include "functions.hpp"
#include <iostream>
#include <algorithm>

namespace MatrixOperations
{

    void readMatrix(std::vector<std::vector<int>>& matrix, int& n)
    {
        std::cout << "Введите размерность матрицы (n <= 100): ";
        std::cin >> n;

        if (n > 100)
        {
            n = 100;
        }

        matrix.resize(n, std::vector<int>(n));
        std::cout << "Введите элементы матрицы:" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cin >> matrix[i][j];
            }
        }
    }

    bool isPrime(int number)
    {
        if (number <= 1) return false;
        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0) return false;
        }
        return true;
    }

    void processMatrix(std::vector<std::vector<int>>& matrix, int n)
    {
        int maxElement = matrix[0][0];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] > maxElement)
                {
                    maxElement = matrix[i][j];
                }
            }
        }

        bool hasDuplicateMax = false;
        for (int i = 0; i < n && !hasDuplicateMax; ++i)
        {
            for (int j = 0; j < n && !hasDuplicateMax; ++j)
            {
                if (matrix[i][j] == maxElement)
                {
                    hasDuplicateMax = true;
                }
            }
        }

        if (hasDuplicateMax) {
            std::vector<std::pair<int, int>> primeCounts(n);
            for (int i = 0; i < n; ++i)
            {
                int count = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (isPrime(matrix[i][j]))
                    {
                        count++;
                    }
                }
                primeCounts[i] = {count, i};
            }

            std::sort(primeCounts.rbegin(), primeCounts.rend());

            std::vector<std::vector<int>> sortedMatrix(n, std::vector<int>(n));
            for (int i = 0; i < n; ++i)
            {
                sortedMatrix[i] = matrix[primeCounts[i].second];
            }
            matrix = sortedMatrix;
        }
    }

    void writeMatrix(const std::vector<std::vector<int>>& matrix, int n)
    {
        std::cout << "Результат:" << std::endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}