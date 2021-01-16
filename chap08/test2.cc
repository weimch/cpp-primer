#include <iostream>

int main() {
  std::cout << "hi!" << std::endl;
  std::cout << "hi!" << std::flush;
  std::cout << "hi!" << std::ends;
  std::cout << std::unitbuf;  // 所有输出操作后都会立即刷新缓冲区
  // 这里的任何输出都会立即刷新，没有缓冲
  std::cout << std::nounitbuf;  // 回到正常的缓冲模式
  // 关联输入流和输出流
  std::cin.tie(&std::cout);
  std::ostream *old_tie = std::cin.tie(nullptr);  // 解绑
  std::cin.tie(&std::cerr);  // 读取cin将会刷新cerr，而不是cout
  std::cin.tie(old_tie);  // 重新绑定cout
}
