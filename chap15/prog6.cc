#include <iostream>
#include "Quote.h"
#include "Bulk_quote.h"

int main() {
  Quote q("isbn1", 1.0);
  Bulk_quote bq("isbn1", 1.0, 2, 0.8);
  print_total(std::cout, q, 2);
  print_total(std::cout, bq, 2);
  return 0;
}
