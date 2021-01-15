#include <iostream>
#include "Debug.h"

int main() {
  constexpr Debug io_sub(false, true, false);
  if (io_sub.any()) {
    std::cerr << "print appropriate error messages" << std::endl;
  }
  constexpr Debug prob(false);
  if (prob.any()) {
    std::cerr << "print an error message" << std::endl;
  }
}
