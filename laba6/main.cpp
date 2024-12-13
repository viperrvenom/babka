#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

// Функция для нахождения суммы цифр числа
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    // Задача 1
    {
        int n;
        cin >> n;
        vector<int> sequence(n);
        bool has19 = false;

        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
            if (sumOfDigits(sequence[i]) == 19) {
                has19 = true;
            }
        }

        if (!has19) {
            sort(sequence.begin(), sequence.end(), greater<int>());
        }

        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Задача 2
    {
        int n;
        cin >> n;
        vector<int> sequence(n);

        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
        }

        sort(sequence.begin(), sequence.end(), [](int a, int b) {
            int sumA = sumOfDigits(a);
            int sumB = sumOfDigits(b);
            if (sumA != sumB) return sumA < sumB;

            string strA = to_string(a);
            string strB = to_string(b);
            if (strA[0] != strB[0]) return strA[0] < strB[0];

            return a < b;
        });

        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Задача 3
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        int maxSum = -1, maxRow = -1;

        for (int i = 0; i < n; ++i) {
            int rowSum = 0;
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
                rowSum += abs(matrix[i][j]);
            }
            if (rowSum > maxSum) {
                maxSum = rowSum;
                maxRow = i;
            }
        }

        for (int j = 0; j < m; ++j) {
            matrix[maxRow][j] = 9999;
        }

        for (const auto& row : matrix) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    // Задача 4
    {
        int n;
        cin >> n;
        vector<int> sequence(n);
        int newSize = 0;

        for (int i = 0; i < n; ++i) {
            cin >> sequence[i];
        }

        for (int i = 0; i < n; ++i) {
            string numStr = to_string(sequence[i]);
            if (numStr.front() == numStr.back()) {
                continue;
            }
            sequence[newSize++] = sequence[i];
            if (numStr.front() == '3') {
                sequence[newSize++] = sequence[i];
            }
        }

        set<int> resultSet(sequence.begin(), sequence.begin() + newSize);
        for (int num : resultSet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}