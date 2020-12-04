#include <iostream>
#include <vector>
#include "Screen.h"

int main() {
  Screen::pos i = 4, j = 5;
  Screen screen = {i, j, ' '};
  std::cout << screen.get() << std::endl;
}
