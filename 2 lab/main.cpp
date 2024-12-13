#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
  int a, b, c;

  cout << "введите значения a, b, c:";
  cin >> a >> b >> c;

  //полупериметр
  double p = (a + b + c) / 2.0;

  //площадь по формуле герона
  double plosh = sqrt(p * (p - a) * (p - b) * (p - c));

  cout << "площадь треугольника: " << plosh << endl;

  return 0;
}