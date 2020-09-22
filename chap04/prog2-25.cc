#include <iostream>

int main() {
  std::cout << "~'q'<<6: " << (~'q'<<6) << std::endl;
  std::cout << "(~'q')<<6: " << ((~'q')<<6) << std::endl;
  std::cout << "~('q'<<6): " << (~'q'<<6) << std::endl;
  std::cout << "~'q': " << (~'q') << std::endl;
  std::cout << "'q': " << int('q') << std::endl;
}