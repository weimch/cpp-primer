#include <vector>
#include <iostream>

int main() {
  std::vector<int> array{2, 4, 6, 7, 8, 9, 12, 14, 16, 18};
  auto beg = array.begin(), end = array.end();
  auto mid = array.begin() + (end - beg) / 2;
  int sought = 13;
  while (mid != end && *mid != sought) {
    if (sought < *mid) {
      end = mid;
    } else {
      beg = mid + 1;
    }
    mid = beg + (end - beg) / 2;
  }
  if (*mid == sought) {
    std::cout << "Found elem: " << *mid << std::endl;
  } else {
    std::cout << "Element not found" << std::endl;
  }
  return 0;
}