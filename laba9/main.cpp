#include <iostream>

int main()
{
    unsigned long long number = 0;
    std:: cout << "Введите целое число типа long long: ";
    std::cin >> number;

    unsigned char* bytePointer = reinterpret_cast<unsigned char*>(&number);

    std::cout << "Содержимое каждого байта числа " << number << ":" << std::endl;

    for (size_t i = 0; i < sizeof(number); ++i)
    {
        std::cout << "Байт " << i << ": " << static_cast<int>(bytePointer[i]) << std::endl;
    }

    return 0;
}