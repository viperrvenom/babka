#include <iostream>
#include <sstream>
#include "functions.hpp"

int main() {
    LinkedList list;
    std::string input;
    std::cout << "Enter a sequence of natural numbers (space-separated): ";
    std::getline(std::cin, input);

    std::istringstream stream(input);
    int number;
    while (stream >> number) {
        list.append(number);
    }

    list.sortByFirstOrLastDigit();
    std::cout << "Processed list: ";
    list.print();

    return 0;
}