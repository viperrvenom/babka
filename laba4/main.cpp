#include <iostream>
using namespace std;

int main() {

    // ▎ Условие 1
    int A, B, C;
    cout << "Введите натуральные числа A, B и C: ";
    cin >> A >> B >> C;

    if (A < B && B < C) {
        cout << "Результат: " << (C - B - A) << endl;
    } else if (A % C == 0) {
        cout << "Результат: " << (A / C + B) << endl;
    } else {
        cout << "Результат: " << (A + B + C) << endl;
    }

    // ▎ Условие 2
    int N;
    cout << "\nВведите код товара (1-5): ";
    cin >> N;

    switch (N) {
        case 1:
            cout << "Название товара: Хлеб" << endl;
            break;
        case 2:
            cout << "Название товара: Молоко" << endl;
            break;
        case 3:
            cout << "Название товара: Яблоки" << endl;
            break;
        case 4:
            cout << "Название товара: Сыр" << endl;
            break;
        case 5:
            cout << "Название товара: Печенье" << endl;
            break;
        default:
            cout << "Ошибка! Код товара неверный." << endl;
    }

    // ▎ Условие 3
    int x;
    cout << "\nВведите значение x (-1 или 1): ";
    cin >> x;

    if (x == -1) {
        cout << "Negative number" << endl;
    } else if (x == 1) {
        cout << "Positive number" << endl;
    } else {
        cout << "ошибка, x может быть -1 или 1." << endl;
    }

    return 0;
}
