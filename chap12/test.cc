#include <iostream>
#include <memory>

int main() {
  int x = 1, *px = &x;
  std::cout << "flag1" << std::endl;
  {
    std::unique_ptr<int> upx(px);
  }
  std::cout << "flag2" << std::endl;
  std::cout << x << std::endl;
}
