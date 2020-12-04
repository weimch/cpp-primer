#ifndef CHAP07_PERSON_
#define CHAP07_PERSON_

#include <string>
#include <iostream>

struct Person{
  std::string name, address;
  auto get_name() const -> std::string const& { return name; }
  auto get_addr() const -> std::string const& { return address; }
};

std::ostream& read(std::ostream&, Person&);
std::istream& print(std::istream&, const Person&);

#endif
