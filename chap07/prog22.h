#ifndef CHAP07_PERSON_
#define CHAP07_PERSON_

#include <string>
#include <iostream>

class Person{
 public:
  auto get_name() const -> std::string const& { return name; }
  auto get_addr() const -> std::string const& { return address; }
 private:
  std::string name, address;
  friend std::istream& read(std::istream& is, Person& person);
};

std::ostream& print(std::ostream& os, const Person& person) {
  os << person.get_name() << " " << person.get_addr();
}

std::istream& read(std::istream& is, Person& person) {
  is >> person.name >> person.address;
  return is;
}


#endif
