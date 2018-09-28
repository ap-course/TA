#include <iostream>

inline int CharToNum(char character) {
  return character - '0';
}

int main() {
  std::string input_num;
  std::cin >> input_num;

  for (auto i = 0; i < input_num.length(); i++) {
    std::cout << input_num[i] << ": ";
    for (auto j = 0; j < CharToNum(input_num[i]); j++) {
      std::cout << input_num[i];
    }
    std::cout << std::endl;
  }

  return 0;
}
