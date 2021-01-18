#include <vector>
#include <iostream>

int main() {
  std::vector<int> v;
  for (std::vector<int>::size_type i = 0; i < 100; ++i) {
    v.push_back(1);
    std::cout << "size:" << v.size() << " capacity:"
              << v.capacity() << std::endl;
  }
  return 0;
}
