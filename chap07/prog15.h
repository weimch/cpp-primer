#pragma once

#include <string>
#include <iostream>

struct Person;
std::istream& read(std::istream&, Person&);

struct Person{
  std::string name, address;
  Person() = default;
  Person(const std::string &sname, const std::string &saddr)
    : name(sname), address(saddr) {}
  explicit Person(std::istream &is) {read(is, *this);}
  auto get_name() const -> std::string const& { return name; }
  auto get_addr() const -> std::string const& { return address; }
};

std::ostream& print(std::ostream&, const Person&);
