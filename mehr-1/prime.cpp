#include <cmath>
#include <iostream>

bool IsPrime(int num) {
  for (auto i = 2; i <= std::sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

void PrintPrimeNumbersInBound(int lower_bound, int upper_bound) {
  std::string separator = "";
  for (auto i = lower_bound + 1; i < upper_bound; i++) {
    if (IsPrime(i)) {
      std::cout << separator << i;
      separator = ",";
    }
  }
  std::cout << std::endl;
}

int main() {
  int lower_bound, upper_bound;
  std::cin >> lower_bound >> upper_bound;
  PrintPrimeNumbersInBound(lower_bound, upper_bound);
  return 0;
}
