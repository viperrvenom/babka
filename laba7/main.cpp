#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int maxElem = INT_MIN;
    
    // чтение матрицы и поиск максимального элемента
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] > maxElem) {
                maxElem = matrix[i][j];
            }
        }
    }
    
    // если в матрице есть еще один элемент, равный максимальному, сортируем строки
    if (hasDuplicateMax(matrix, maxElem)) {
        sortMatrixByPrimeCount(matrix, n);
    }
    
    // выводим матрицу (возможно, отсортированную)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}