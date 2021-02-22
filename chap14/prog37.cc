#include <vector>
#include <algorithm>
#include <iostream>

class IsIntEqual {
 public:
  IsIntEqual(int v) : value(v) { }
  bool operator()(int a) {
    return a == value;
  }
 private:
  int value;
};

int main() {
  std::vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};
  std::replace_if(vec.begin(), vec.end(), IsIntEqual(3), 5);
  for (int i : vec) std::cout << i << " ";
  std::cout << std::endl;
}
