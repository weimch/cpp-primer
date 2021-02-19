#pragma once

#include <vector>
#include <algorithm>

class Foo {
 public:
  Foo sorted() && {
    std::sort(data.begin(), data.end());
    return *this;
  }
  Foo sorted() const & {
    Foo ret(*this);
    std::sort(ret.data.begin(), ret.data.end());
    return ret;
  }
 private:
  std::vector<int> data;
};
