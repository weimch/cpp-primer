#include <iostream>

int main() {
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 <= v2) {
        int val = v1;
        while (val <= v2) {
            std::cout << val << " ";
            ++val;
        }
    } else {
        std::cout << "first number less than second number" << std::endl;
    }
    return 0;
}