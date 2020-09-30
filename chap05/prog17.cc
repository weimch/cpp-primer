#include <iostream>
#include <vector>

int main() {
  std::vector<int> v2{0, 1, 1, 2};
  std::vector<int> v1{0, 1, 1, 2, 3, 5, 8};
  if (v1.size() > v2.size()) {
    std::vector<int> tmp = v1;
    v1 = v2;
    v2 = v1;
  }
  for (decltype(v1.size()) i = 0; i < v1.size(); ++i) {
    if (v1[i] != v2[i]) {
      std::cout << "Prefix not match" << std::endl;
      return -1;
    }
  }
  std::cout << "Prefix match" << std::endl;
  return 0;
}
