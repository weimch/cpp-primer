#include <iostream>
#include <string>

#include "StrBlob.h"
#include "StrBlobPtr.h"

int main() {
  StrBlob b({"hello", "world", "weimch"});
  for (StrBlobPtr bptr = b.begin(); bptr != b.end(); bptr.incr()) {
    std::cout << bptr.deref() << std::endl;
  }
  return 0;
}
