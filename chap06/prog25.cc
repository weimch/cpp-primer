#include <iostream>

int main(int argc, char *argv[]) {
  std::string ss;
  for (int i = 1; i < argc; i ++) {
    ss += argv[i];
  }
  std::cout << ss << std::endl;
  return 0;
}
