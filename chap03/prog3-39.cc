#include <string>
#include <cstring>
#include <iostream>

int main() {
  std::string s1 = "hello world";
  std::string s2 = "hello world";
  if (s1 > s2) {
    std::cout << "s1 is bigger" << std::endl;
  } else if(s1 < s2) {
    std::cout << "s2 is bigger" << std::endl;
  } else {
    std::cout << "s1 is equal to s2" << std::endl;
  }
  const char carr1[] = "hello world";
  const char carr2[] = "hello world";
  if (std::strcmp(carr1, carr2) > 0) {
    std::cout << "carr1 is bigger" << std::endl;
  } else if (std::strcmp(carr1, carr2) < 0) {
    std::cout << "carr2 is bigger" << std::endl;
  } else {
    std::cout << "carr1 is equal to carr2" << std::endl;
  }
  return 0;
}