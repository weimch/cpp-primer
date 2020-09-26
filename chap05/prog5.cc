#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> scores{"F", "D", "C", "B", "A", "A++"};
  std::string lettergrade;
  int grade = 92;
  if (grade < 60) {
    lettergrade = scores[0];
  } else {
    lettergrade = scores[(grade-50)/10];
    if (grade%10 < 3) {
      lettergrade += "-";
    }
    if (grade%10 > 7) {
      lettergrade += "+";
    }
  }
  std::cout << lettergrade << std::endl;
}