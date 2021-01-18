#include <string>
#include <iostream>

int main() {
  std::string s = "ab2c3d7R4E6";
  std::string nums = "0123456789";
  std::string::size_type pos = 0;
  while ((pos = s.find_first_of(nums, pos)) != std::string::npos) {
    std::cout << "find num: " << s[pos] << std::endl;
    ++pos;
  }
  pos = 0;
  while ((pos = s.find_first_not_of(nums, pos)) != std::string::npos) {
    std::cout << "find char: " << s[pos] << std::endl;
    ++pos;
  }
  return 0;
}
