#include <vector>
#include <algorithm>
#include "HasPtr3.h"

int main() {
  std::vector<HasPtr3> vec;
  for (int i = 50; i >= 0; --i) {
    vec.push_back(HasPtr3(std::to_string(i)));
  }
  std::sort(vec.begin(), vec.end());
  return 0;
}
