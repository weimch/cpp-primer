#include <iostream>
#include <string>

using string = std::string;

string fullName(string name, string prefix, string subfix) {
  name.insert(0, prefix);
  name.insert(name.size(), subfix);
  return name;
}

int main() {
  std::cout << fullName("weimch", "Mr.", "233") << std::endl;
}
