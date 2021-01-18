#include <vector>
#include <iostream>

int main() {
  std::vector<int> vi{0, 1, 2, 3, 4, 5, 6};
  auto iter = vi.begin();
  int loop_count = 0;
  while (iter != vi.end()) {
    if (*iter % 2)
      iter = vi.insert(iter, *iter);
    ++iter;
    for (const auto &e : vi) {
      std::cout << e << " ";
    }
    std::cout << std::endl;
    if (++loop_count == 5) break;
  }
  return 0;
}
