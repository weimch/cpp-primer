#include <iostream>
#include <vector>
#include <string>

int main() {
  std::vector<std::string> scores{"F", "D", "C", "B", "A", "A++"};
  std::string lettergrade;
  int grade = 92;
  lettergrade = (grade < 60) ? scores[0] : scores[(grade-50)/10];
  lettergrade = (grade % 10 < 3) ? (lettergrade + "-") : (grade % 10 > 7) ? (lettergrade + "+") : lettergrade;
  std::cout << lettergrade << std::endl;
}