#include <cstring>
#include <iostream>

int main() {
  const char cstr1[] = "hello";
  const char cstr2[] = "world";
  char buffer[256];
  std::strcpy(buffer, cstr1);
  std::strcat(buffer, " ");
  std::strcat(buffer, cstr2);
  std::cout << buffer << std::endl;
  return 0;
}