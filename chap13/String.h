#pragma once

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
  String(const String& str) {
    std::cout << "String construt copy" << std::endl;
    beg = alloc.allocate(str.size());
    end = std::uninitialized_copy(str.beg, str.end, beg);
  }
  String(String &&s) noexcept {
    std::cout << "String move construt copy" << std::endl;
    beg = s.beg;
    end = s.end;
    s.beg = s.end = nullptr;
  }
  String& operator=(const String& rhs) {
    std::cout << "String assignment copy" << std::endl;
    auto nbeg = alloc.allocate(rhs.size());
    auto nend = std::uninitialized_copy(rhs.beg, rhs.end, nbeg);
    free();
    beg = nbeg;
    end = nend;
    return *this;
  }
  String &operator=(String &&s) {
    std::cout << "String move assignment copy" << std::endl;
    if (this != &s) {
      free();
      beg = s.beg;
      end = s.end;
      s.beg = s.end = nullptr;
    }
    return *this;
  }
  size_t size() const {
    return end - beg;
  }
  void print() const {
    for (auto p = beg; p != end; ++p) {
      std::cout << *p;
    }
    std::cout << std::endl;
  }
  ~String() {
    free();
  }

 private:
  static std::allocator<char> alloc;
  char* beg, *end;
  void free() {
    if (beg) {
      for (auto p = end; p != beg;) {
        alloc.destroy(--p);
      }
      alloc.deallocate(beg, end - beg);
    }
  }
};

std::allocator<char> String::alloc;
