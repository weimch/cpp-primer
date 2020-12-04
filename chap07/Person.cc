#include <iostream>
#include <string>
#include "Person.h"

std::ostream& print(std::ostream& os, const Person& person) {
  os << person.get_name() << " " << person.get_addr();
}

std::istream& read(std::istream& is, Person& person) {
  is >> person.name >> person.address;
  return is;
}
