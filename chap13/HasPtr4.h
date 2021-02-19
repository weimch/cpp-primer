#pragma once

#include <string>
#include <utility>
#include <iostream>

class HasPtr4 {
  friend void swap(HasPtr4&, HasPtr4&);

 public:
  HasPtr4(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr4(const HasPtr4 &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
  HasPtr4& operator=(const HasPtr4 &hp) {
    auto new_p = new std::string(*hp.ps);
    delete ps;
    ps = new_p;
    i = hp.i;
    return *this;
  }
  HasPtr4& operator=(HasPtr4 &&hp) {
    if (this != &hp) {
      delete ps;
      ps = hp.ps;
      i = hp.i;
      hp.ps = nullptr;
    }
    return *this;
  }
  // HasPtr3& operator=(HasPtr3 hp) {
  //   swap(*this, hp);
  //   return *this;
  // }
  ~HasPtr4() {
    delete ps;
  }
  bool operator<(const HasPtr4& hp) {
    return *ps < *hp.ps;
  }

 private:
  std::string *ps;
  int i;
};

inline void swap(HasPtr4 &lhs, HasPtr4 &rhs) {
  std::cout << "executing swap for " << *lhs.ps << " and " << *rhs.ps << std::endl;
  std::swap(lhs.ps, rhs.ps);
  std::swap(lhs.i, rhs.i);
}
