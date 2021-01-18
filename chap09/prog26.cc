#include <iostream>
#include <vector>
#include <list>

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> vec(std::begin(ia), std::end(ia));
  std::list<int> ls(std::begin(ia), std::end(ia));

  std::list<int>::iterator ls_iter = ls.begin();
  while (ls_iter != ls.end()) {
    if (*ls_iter % 2 == 1)
      ls_iter = ls.erase(ls_iter);
    else
      ++ls_iter;
  }

  std::vector<int>::iterator vec_iter =  vec.begin();
  while (vec_iter != vec.end()) {
    if (*vec_iter % 2 == 0)
      vec_iter = vec.erase(vec_iter);
    else
      ++vec_iter;
  }

  std::cout << "list: ";
  for (const auto &e : ls) {
    std::cout << e << " ";
  }
  std::cout << std::endl << "vector: ";
  for (const auto &e : vec) {
    std::cout << e << " ";
  }
  std::cout << std::endl;

  return 0;
}
