int main() {
  int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto ia2 = ia; // ia2是一个指针
  // ia2 = 4; // 错误：ia2是一个指针，不能用int值给指针赋值
  decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // ia3是一个int[10]的类型
  // ia3 = ia2; // 不能使用整型指针给数组赋值
  ia3[4] = 200; // 把200赋值给ia3的一个元素
}