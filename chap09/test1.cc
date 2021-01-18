#include <iostream>
#include <string>

int main() {
  // std::string s = "some string", s2 = "some other string";
  // s.insert(0, s2);
  // s.insert(0, "hhh");
  const char *cp = "Stately, plump Buck";
  std::string s;
  s.assign(cp, 7);
  s.insert(s.size(), cp + 7);
  std::cout << s << std::endl;
}
