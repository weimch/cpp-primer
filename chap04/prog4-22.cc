#include <iostream>
#include <string>

int main() {
  int grade = 70;
  std::string finalgrade = (grade > 90) ? "high pass" : 
                            (grade < 60) ? "fail" : 
                            (grade < 75) ? "low pass" : "pass";
  std::cout << finalgrade << std::endl;
  if (grade > 90) {
    std::cout << "high pass";
  } else if (grade > 75) {
    std::cout << "pass";
  } else if (grade > 60) {
    std::cout << "low pass";
  } else {
    std::cout << "fail";
  }
  std::cout << std::endl;
  return 0;
}