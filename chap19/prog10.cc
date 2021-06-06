#include <iostream>
#include <typeinfo>

class A {};
class B : public A {};
class C : public B {};

int main() {
  A *pa = new C;
  std::cout << typeid(pa).name() << std::endl;

  C cobj;
  A &ra = cobj;
  std::cout << typeid(&ra).name() << std::endl;

  B *px = new B;
  A &ra2 = *px;
  std::cout << typeid(A).name() << std::endl;

  return 0;
}
