#include <iostream>

int FuncInvokeCount(int start_by) {
  static int counter = start_by;
  return ++counter;
}

int main() {
  for (int i = 0; i < 10; i ++) {
    std::cout << FuncInvokeCount(i*2) << std::endl;
  }
  return 0;
}
