/* 
1. 
Переменная - это символ, содержащий в себе какую-либо информацию (данные). В зависимости от количество данных в переменной следует выбирать определенный тип данных. 
 
2. 
Типы данных 
 
Целочисленные: int, short, long, long long 
Целочисленные без знака: unsigned int, unsigned short, unsigned long, unsigned long long 
Вещественные: float, double, long double 
Символьные: char, unsigned char 
Логический - bool 
 
3.
 
Name                        
 
char - 1Б                   
unsigned char - 1Б          
bool - 1Б                   
short - 2Б                   
unsigned short - 2Б             
float - 4Б                  
int - 4Б                     
unsigned int - 4Б            
long - 4Б/8Б                
unsigned long - 4Б/8Б       
long long - 8Б              
unsigned long long - 8Б     
double - 8Б                  
long double - 8Б/16Б        

4.

[от и до]
I-1 * 2^7;
2^7 - 1]
[0; 2^8 - 1]
[0; 1]
[-1 * 2^15;
2^15 - 11
[0; 2^16 - 1]
[-3.4E+38; 3.4E+38]
I-1 * 2^31; 2^31 - 11
[0; 2^32 - 1]
2^63 - 11
[-1 * 2^31; 2^31 - 11 / [-1 * 2^63; 2^63 - 11
[0; 2^32 - 11 / [0; 2^64 - 1]
I-1 * 2^63; 2^63 - 1]
[0; 2^64 - 1]
[-1. 7E+308; 1.7E+308]
[-1. 7E+308; 1.7E+308] / L-1.1E+4932;
1.1E+4932]
 
 
*/ 
 
#include <iostream> 
//#include <locale.h> 
 
using namespace std; 
 
int main() 
{ 
    //setlocale(LC_ALL, "Russian"); 
    cout << "Целочисленные:" << endl; 
    cout << "char (1 байт) от -128 до 127" << endl; 
    cout << "short (2 байта) от -32768 до 32767" << endl; 
    cout << "int (4 байта) от -2^31 до 2^31-1" << endl; 
    cout << "long long (8 байт) от -2^63 до 2^63-1" << endl; 
    cout << "unsigned int(4 байта) от 0 до 2 ^ 32 - 1" << endl; 
    cout << "Символьный:" << endl; 
    cout << "char (1 байт) от -128 до 127" << endl; 
    cout << "Вещественный:" << endl; 
    cout << "double (8 байт) от 15 до 16 цифр" << endl; 
    cout << "float (4 байта) от 6 до 7 цифр" << endl; 
    cout << "Логический:" << endl; 
    cout << "bool (1 байт)" << endl; 
    cout << "true (2 байта) (значение 1)" << endl; 
    cout << "false (2 байта) (значение 0)" << endl; 
 
   //6. 
 
    char a = 10; 
    char b = 5; 
    cout << a * b << endl; 
 
    short c = 20400; 
    short d = 10000; 
    cout << c - d << endl; 
 
    int e = 2500000; 
    int f = 3000000; 
    cout << e + f << endl; 
 
    char g = 43; //  Код выведет плюс исходя из ASCII таблицы 
    cout << g << endl; 
 
    double h = 123.0; 
    cout << h / 23 << endl; 
 
    float j = 123.0f; 
    cout << j / 23 << endl; 
 
    int num1= 10; 
    int num2= 15; 
    bool total {num1 > num2}; // Код выведет 0 (false), т.к 10 не больше 15 
    cout << total << endl; 
 
    int num3 = 10; 
    int num4 = 15; 
    bool total2 { num3 < num4 }; // Код выведет 1 (true), т.к 15 больше 10 
    cout << total2 << endl; 
 
}