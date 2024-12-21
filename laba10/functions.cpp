#include "functions.hpp"
#include <iostream>
#include <cmath>

// Конструктор
LinkedList::LinkedList() : head(nullptr) {}

// Деструктор
LinkedList::~LinkedList() {
    deleteList();
}

// Добавление элемента в конец списка
void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Печать списка
void LinkedList::print() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Удаление однозначных чисел
void LinkedList::removeSingleDigits() {
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->value < 10) {
            if (previous == nullptr) {  // Удаление первого элемента
                head = current->next;
                delete current;
                current = head;
            } else {  // Удаление элемента в середине/конце
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }
}

// Дублирование палиндромов
void LinkedList::duplicatePalindromes() {
    Node* current = head;
    while (current != nullptr) {
        if (isPalindrome(current->value)) {
            Node* newNode = new Node(current->value);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
    }
}

// Проверка на палиндром
bool LinkedList::isPalindrome(int num) const {
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    return original == reversed;
}

// Получение первой цифры числа
int LinkedList::getFirstDigit(int num) const {
    while (num >= 10) {
        num /= 10;
    }
    return num;
}

// Получение последней цифры числа
int LinkedList::getLastDigit(int num) const {
    return num % 10;
}

// Упорядочить последовательность по первой или последней цифре
void LinkedList::sortByFirstOrLastDigit() {
    Node* temp = head;
    bool sorted = false;

    // Проверяем, упорядочена ли последовательность по первой или последней цифре
    while (temp != nullptr && temp->next != nullptr) {
        int first1 = getFirstDigit(temp->value);
        int first2 = getFirstDigit(temp->next->value);
        int last1 = getLastDigit(temp->value);
        int last2 = getLastDigit(temp->next->value);

        if ((first1 != first2 && last1 != last2) || (first1 == first2 && last1 == last2)) {
            sorted = true;
            break;
        }
        temp = temp->next;
    }

    if (sorted) {
        sort();
    } else {
        removeSingleDigits();
        duplicatePalindromes();
    }
}

// Сортировка списка по возрастанию первой цифры
void LinkedList::sort() {
    if (head == nullptr) return;

    Node* current = head;
    Node* index = nullptr;
    int temp;

    while (current != nullptr) {
        index = current->next;
        while (index != nullptr) {
            if (getFirstDigit(current->value) > getFirstDigit(index->value)) {
                temp = current->value;
                current->value = index->value;
                index->value = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}

// Очистка списка
void LinkedList::deleteList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}