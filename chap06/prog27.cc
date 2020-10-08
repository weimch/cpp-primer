#include <iostream>
#include <initializer_list>

int CountSum(std::initializer_list<int> il) {
  int sum = 0;
  for (const int &elem : il) {
    sum += elem;
  }
  return sum;
}

int main() {
  std::cout << CountSum({1, 2, 3, 4, 5}) << std::endl;
  return 0;
}
