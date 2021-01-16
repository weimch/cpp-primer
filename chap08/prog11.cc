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
  for (const auto &info : people) {
    std::cout << "name: " << info.name << "phones: ";
    for (const auto &ps : info.phones) {
      std::cout << ps << " ";
    }
    std::cout << std::endl;
  }
}
