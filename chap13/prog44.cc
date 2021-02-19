#include <memory>
#include <cstring>
#include <iostream>

class String {
 public:
  String() {
    end = beg = alloc.allocate(0);
  }
  explicit String(const char *chs) {
    auto len = std::strlen(chs);
    beg = alloc.allocate(len);
    end = std::uninitialized_copy_n(chs, len, beg);
  }
  size_t size() {
    return end - beg;
  }
  void print() {
    for (auto p = beg; p != end; ++p) {
      std::cout << *p;
    }
    std::cout << std::endl;
  }
  ~String() {
    if (beg) {
      for (auto p = end; p != beg;) {
        alloc.destroy(--p);
      }
      alloc.deallocate(beg, end - beg);
    }
  }

 private:
  static std::allocator<char> alloc;
  char* beg, *end;
};

std::allocator<char> String::alloc;

int main() {
  String str("123");
  str.print();
  std::cout << str.size() << std::endl;
}
