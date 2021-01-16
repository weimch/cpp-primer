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
  while (getline(std::cin, line)) {
    PersonInfo info;
    std::istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
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
