#include <cmath>
#include <iostream>

int GetGreatestCommonDivisor(int num1, int num2) {
  if (num2 == 0) {
    return num1;
  }
  return GetGreatestCommonDivisor(num2, num1 % num2);
}

int main() {
  int num1, num2;
  std::cin >> num1 >> num2;

  num1 = std::abs(num1);
  num2 = std::abs(num2);
  if (num2 < num1) {
    std::swap(num1, num2);
  }

  std::cout << GetGreatestCommonDivisor(num1, num2) << std::endl;
  return 0;
}
