#pragma_once

#include <string>
#include <iostream>

// Структура для узла списка
struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

// Класс для работы с односвязным списком
class LinkedList {
public:
    LinkedList();  // Конструктор
    ~LinkedList(); // Деструктор для очистки памяти

    void append(int value);  // Добавление элемента в конец списка
    void print() const;      // Печать списка
    void removeSingleDigits(); // Удаление однозначных чисел
    void duplicatePalindromes(); // Дублирование палиндромов
    void sortByFirstDigit(); // Сортировка по первой цифре
    void sortByFirstOrLastDigit(); // Упорядочить по первой или последней цифре

private:
    Node* head;  // Голова списка

    // Вспомогательные функции
    bool isPalindrome(int num) const;  // Проверка на палиндром
    int getFirstDigit(int num) const;  // Получение первой цифры
    int getLastDigit(int num) const;   // Получение последней цифры
    void sort();  // Сортировка списка по возрастанию
    void deleteList();  // Очистка списка
};

#endif // FUNCTIONS_HPP
