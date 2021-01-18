#include <iostream>
#include <string>

using string = std::string;

void replaceStr(string &s, const string &oldVal, const string &newVal) {
  string::size_type idx = 0;
  while (idx <= s.size() - oldVal.size()) {
    if (oldVal == s.substr(idx, oldVal.size())) {
      s.replace(idx, oldVal.size(), newVal);
      idx += newVal.size();
    } else {
      ++idx;
    }
  }
}

int main() {
  string s("To drive straight thru is a foolish, tho courageous act.");
  replaceStr(s, "tho", "though");
  replaceStr(s, "thru", "through");
  std::cout << s << std::endl;
}
