#include <iostream>

int main() {
  int *a = new int[1];
  throw a;
  return 0;
}
