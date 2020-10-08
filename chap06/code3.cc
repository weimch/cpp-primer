#include <iostream>

int main() {
  std::cerr << "Error: " << __FILE__ << " : in function " << __func__
    << " at line " << __LINE__ << std::endl
    << "    Compiled on " << __DATE__ << " at " << __TIME__ << std::endl;
}
