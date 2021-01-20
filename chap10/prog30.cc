#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
  std::istream_iterator<int> cin_iter(std::cin), cin_eof;
  std::ostream_iterator<int> cout_iter(std::cout);
  std::vector<int> v;
  std::copy(cin_iter, cin_eof, std::back_inserter(v));
  std::sort(v.begin(), v.end());
  for (const auto &e : v) {
    std::cout << e << std::endl;
  }
  return 0;
}
