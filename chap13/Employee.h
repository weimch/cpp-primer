#include <string>

class Employee {
 public:
  Employee() : id(gid++) { }
  explicit Employee(std::string name) : name(name) {
    Employee();
  }
  explicit Employee(const Employee &e) : name(e.name), id(gid++) { }
 private:
  static unsigned gid;
  std::string name;
  unsigned id;
};

unsigned Employee::gid = 0;
