#include <string>
#include <cstring>
#include <iostream>

int main() {
  const char *chr1 = "hello", *chr2 = "world";
  int len = std::strlen(chr1) + std::strlen(chr2);
  char *chr = new char[len+1];
  snprintf(chr, len+1, "%s%s", chr1, chr2);
  std::cout << chr << std::endl;
  std::string str1 = "hello", str2 = "world";
  std::cout << str1 + str2 << std::endl;
  delete [] chr;
  return 0;
}
