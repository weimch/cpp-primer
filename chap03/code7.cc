#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> scores(11);
  unsigned grade;
  while (std::cin >> grade) {
    if (grade <= 100) {
      ++scores[grade/10];
    }
  }
  for (const auto &count : scores) {
    std::cout << count << " ";
  }
}