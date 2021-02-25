#include "Basket.h"
#include <iostream>
#include "Bulk_quote.h"
#include "Quote.h"

int main() {
  Basket basket;
  basket.add_item(Quote("1", 1));
  basket.add_item(Bulk_quote("2", 1, 1, 0.2));
  basket.add_item(Bulk_quote("2", 1, 1, 0.2));
  basket.total_receipt(std::cout);
  return 0;
}
