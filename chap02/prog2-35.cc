#include <iostream>

int main() {
  const int i = 42;
  auto j = i; // j是整形，可以被赋值
  j = 48;
  const auto &k = i; // k是对i的整形引用，不可被赋值
  // k = 48; // error occurs
  auto *p = &i; // p是指向常量变量的指针
  // p = 48; // 不可给指针赋值
  // *p = 48; // 不可给常量变量赋值
  const auto j2 = i, &k2 = i; // j2是整形变量，不可更改
  // j2 = 48;
  // k2的意义和k一样
  // k2 = 48;
}