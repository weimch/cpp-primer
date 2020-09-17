#include <iostream>
#include "Sales_item.h"

int main() {
  Sales_item item_sum, item;
  if(std::cin >> item) {
    item_sum = item;
    while (std::cin >> item) {
      if (item.isbn() != item_sum.isbn()) {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
      }
      item_sum += item;
    }
    std::cout << item_sum << std::endl;
  }
  return 0;
}