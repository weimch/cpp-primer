#include "Account.h"

int main() {
  double r;
  // 1. 通过类域运算符来访问
  r = Account::rate();
  // 2. 通过类对象来访问
  Account ac1;
  Account *ac2 = &ac1;
  r = ac1.rate();
  r = ac2->rate();
  return 0;
}
