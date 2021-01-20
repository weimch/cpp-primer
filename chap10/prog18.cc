#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

void printVector(const std::vector<std::string> &words) {
  for (const std::string &e : words) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words) {
  std::cout << "Before Sort" << std::endl;
  printVector(words);
  std::sort(words.begin(), words.end());
  std::cout << "After Sort" << std::endl;
  printVector(words);
  auto eidx = std::unique(words.begin(), words.end());
  std::cout << "After Unique" << std::endl;
  printVector(words);
  words.erase(eidx, words.end());
  std::cout << "After erase" << std::endl;
  printVector(words);
}

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz) {
  elimDups(words);
  std::stable_sort(words.begin(), words.end(),
    [](const std::string &a, const std::string &b) { return a.size() < b.size(); });
  std::cout << "After stable sort" << std::endl;
  printVector(words);
  auto wc = std::partition(words.begin(), words.end(),
    [sz](const std::string &a) { return a.size() >= sz; });
  auto count = wc - words.begin();
  std::cout << count << " words of length " << sz << " or longer" << std::endl;
  std::for_each(words.begin(), wc,
    [](const std::string &s) {std::cout << s << " ";});
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> words{"the", "quick", "red", "fox", "jumps",
    "over", "the", "slow", "red", "turtle"};
  biggies(words, 4);
  return 0;
}
