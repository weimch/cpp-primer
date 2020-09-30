#include <iostream>
#include <string>

int main() {
  std::string rsp;
  do {
    std::cout << "please enter two string to compare: ";
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::string ss = s1.size() < s2.size() ? s1 : s2;
    std::cout << "The length of " << ss << " is smaller\n\n"
              << "More? Enter yes or no: ";
    std::flush(std::cout);
    std::cin >> rsp;
  } while (!rsp.empty() && rsp[0] != 'n');
  return 0;
}
