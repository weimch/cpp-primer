#include <iostream>

int getIval(int x) {
  return x * x;
}

int main() {
  constexpr unsigned ival = getIval(256), jval = 1024, kval = 4096;
  unsigned bufsize;
  unsigned swt = 512;
  switch (swt) {
    case ival:
      bufsize = ival * sizeof(int);
      break;
    case jval:
      bufsize = jval * sizeof(int);
      break;
    case kval:
      bufsize = kval * sizeof(int);
      break;
  }
}