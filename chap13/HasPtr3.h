#pragma once

#include <string>
#include <utility>
#include <iostream>

class HasPtr3 {
  friend void swap(HasPtr3 &, HasPtr3&);
 public:
  HasPtr3(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr3(const HasPtr3 &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  HasPtr3& operator=(const HasPtr3 &hp) {
    auto new_p = new std::string(*hp.ps);
    delete ps;
    ps = new_p;
    i = hp.i;
    return *this;
  }
  // HasPtr3& operator=(HasPtr3 hp) {
  //   swap(*this, hp);
  //   return *this;
  // }
  ~HasPtr3() {
    delete ps;
  }
  bool operator<(const HasPtr3& hp) {
    return *ps < *hp.ps;
  }

 private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr3 &lhs, HasPtr3 &rhs) {
  std::cout << "executing swap for " << *lhs.ps << " and " << *rhs.ps << std::endl;
  std::swap(lhs.ps, rhs.ps);
  std::swap(lhs.i, rhs.i);
}
