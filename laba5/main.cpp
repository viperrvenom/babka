#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 1
    int n;
    cout << "Введите количество элементов последовательности: ";
    cin >> n;

    vector<double> sequence(n);
    cout << "Введите числа последовательности: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    double product = 1.0;      // Произведение отрицательных чисел
    double minNumber = 1e9;    // Наименьшее отрицательное число
    int minIndex = -1;         // Индекс наименьшего числа в последовательности
    bool found = false;        // Флаг для проверки существования подходящих чисел

    for (int i = 0; i < n; i++) {
        if (sequence[i] < 0 && (sequence[i] - (int)sequence[i]) != 0) {  // Проверка условия
            product *= sequence[i];
            if (sequence[i] < minNumber) {
                minNumber = sequence[i];
                minIndex = i + 1; // Для вывода позиции (счёт с 1)
            }
            found = true;
        }
    }

    if (found) {
        cout << "Произведение отрицательных чисел с ненулевой дробной частью: " << product << endl;
        cout << "Наименьшее из таких чисел: " << minNumber << endl;
        cout << "Позиция этого числа в последовательности: " << minIndex << endl;
    } else {
        cout << "Таких чисел не найдено." << endl;
    }

    // 2
    long long N;
    cout << "Введите натуральное число N: ";
    cin >> N;

    int minDigit = 9;  // Начальная минимальная цифра

    while (N > 0) {
        int digit = N % 10;  // Последняя цифра числа
        if (digit < minDigit) {
            minDigit = digit;
        }
        N /= 10;  // Убираем последнюю цифру
    }

    cout << "Наименьшая цифра числа N: " << minDigit << endl;

    return 0;
}