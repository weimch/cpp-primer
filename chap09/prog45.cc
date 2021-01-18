#include <iostream>
#include <string>

using string = std::string;

string fullName(string name, string prefix, string subfix) {
  auto ps = name.begin();
  name.insert(ps, prefix.begin(), prefix.end());
  name.append(subfix);
  return name;
}

int main() {
  std::cout << fullName("weimch", "Mr.", "233") << std::endl;
}
