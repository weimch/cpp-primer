#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

class WordCounter {
  size_t sz;
 public:
  WordCounter(size_t t) : sz(t) { }
  bool operator()(std::string str) {
    return str.size() == sz;
  }
};

int main() {
  std::vector<std::string> vec{"1", "22", "333"};

  std::cout << std::count_if(vec.begin(), vec.end(), WordCounter(2))
    << std::endl;

  return 0;
}
