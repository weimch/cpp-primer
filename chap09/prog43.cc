#include <iostream>
#include <string>

using string = std::string;

void replaceStr(string &s, const string &oldVal, const string &newVal) {
  auto curr = s.begin();
  while (curr != s.end() - oldVal.size()) {
    if (oldVal == string(curr, curr + oldVal.size())) {
      curr = s.erase(curr, curr + oldVal.size());
      curr = s.insert(curr, newVal.begin(), newVal.end());
      curr += newVal.size();
    } else {
      ++curr;
    }
  }
}

int main() {
  string s("To drive straight thru is a foolish, tho courageous act.");
  replaceStr(s, "tho", "though");
  replaceStr(s, "thru", "through");
  std::cout << s << std::endl;
}
