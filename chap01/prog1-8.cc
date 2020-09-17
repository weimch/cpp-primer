#include <iostream>

int main() {
    // 1. 正确
    std::cout << "/*";
    // 2. 正确
    std::cout << "*/";
    // 3. 错误
    // std::cout << /* "*/" */;
    // 3. 更正
    std::cout << /* */ "*/";
    // 4. 正确
    std::cout << /* "*/" /* " /*" */;
}