#include <vector>

int main() {
  std::vector<int> vec{1, 2, 3};
  auto begin = vec.begin();
  while (begin != vec.end()) {
    ++begin;
    vec.insert(begin, 42);
  }
}
