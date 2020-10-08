#include <iostream>
#include <initializer_list>
#include <string>
#include <vector>

void error_msg(std::initializer_list<std::string> il) {
  for (auto beg = il.begin(); beg != il.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::string expected, actual;
  if (expected != actual) {
    error_msg({"functionX", "expected", "actual"});
  } else {
    error_msg({"functionX", "okay"});
  }
  return 0;
}