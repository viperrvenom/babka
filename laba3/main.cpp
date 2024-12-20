#include <iostream>

using namespace std;

int main() {
    unsigned int x, i; // x - число, i - индекс бита
    cout << "Введите число x (0 < x < 10^9): ";
    cin >> x;

    cout << "Введите индекс бита i (начиная с 0): ";
    cin >> i;

    if (x <= 0 || x >= 1000000000) {
        cout << "Число x должно быть в диапазоне от 1 до 10^9!" << endl;
        return 1;
    }

    x &= ~(1U << i); // Устанавливаем i-ый бит в 0

    cout << "Результат: " << x << endl;

    return 0;
}