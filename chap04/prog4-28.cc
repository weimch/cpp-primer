#include <iostream>

int main() {
  std::cout << "bool:\t" << sizeof(bool) << std::endl;
  std::cout << "char:\t" << sizeof(char) << std::endl;
  std::cout << "int:\t" << sizeof(int) << std::endl;
  std::cout << "long:\t" << sizeof(long) << std::endl;
  std::cout << "long int:\t" << sizeof(long int) << std::endl;
  std::cout << "long long:\t" << sizeof(long long) << std::endl;
  std::cout << "float:\t" << sizeof(float) << std::endl;
  std::cout << "double:\t" << sizeof(double) << std::endl;
  std::cout << "long double:\t" << sizeof(long double) << std::endl;
  std::cout << "char*:\t" << sizeof(char*) << std::endl;
  std::cout << "int*:\t" << sizeof(int*) << std::endl;
}