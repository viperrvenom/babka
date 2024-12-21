#include "functions.hpp"

int main() {
    std::vector<std::vector<int>> matrix;
    int n;

    MatrixOperations::readMatrix(matrix, n);
    MatrixOperations::processMatrix(matrix, n);
    MatrixOperations::writeMatrix(matrix, n);

    return 0;
}