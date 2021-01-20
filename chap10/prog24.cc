#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>

bool check_size(const std::string &s, std::string::size_type sz) {
  return s.size() < sz;
}

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  std::string word("hello");
  auto f = std::bind(check_size, word, std::placeholders::_1);
  auto result = std::find_if(v.begin(), v.end(), f);
  std::cout << *result << std::endl;
  return 0;
}
