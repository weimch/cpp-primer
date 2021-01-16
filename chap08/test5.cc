#include <string>
#include <vector>
#include <iostream>
#include <sstream>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  while (getline(std::cin, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    record.clear();
    people.push_back(info);
  }
  for (const auto &entry : people) {
    std::ostringstream formatted, badNums;
    for (const auto &nums : entry.phones) {
      if (nums[0] == '2') {
        badNums << " " << nums;
      } else {
        formatted << " " << nums;
      }
    }
    if (badNums.str().empty()) {
      std::cout << entry.name << " " << formatted.str() << std::endl;
    } else {
      std::cerr << "input error: " << entry.name << " invalid number(s) "
                << badNums.str() << std::endl;
    }
  }
}
