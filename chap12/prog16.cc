#include <memory>

int main() {
  std::unique_ptr<int> p(new int(2));
  std::unique_ptr<int> p2 = p;
  return 0;
}
