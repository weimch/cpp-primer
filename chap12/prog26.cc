#include <memory>
#include <string>
#include <iostream>

int main() {
  std::allocator<std::string> a;
  std::string* ps = a.allocate(100), s;
  auto *qs = ps;
  while (std::cin >> s && s != "@q") {
    a.construct(qs++, s);
  }
  std::cout << "===============" << std::endl;
  while (qs != ps) {
    std::cout << *--qs << std::endl;
    a.destroy(qs);
  }
  a.deallocate(ps, 100);
}
