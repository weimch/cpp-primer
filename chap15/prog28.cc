#include <vector>

#include "Quote.h"
#include "Bulk_quote.h"


int main() {
  std::vector<Quote> vec_q{
    Bulk_quote("1", 1, 1, 0.1),
    Bulk_quote("2", 2, 1, 0.2),
    Bulk_quote("3", 3, 1, 0.3)
  };
  double sum_p = 0.0;
  for (const auto &q : vec_q) {
    sum_p += q.net_price(2);
  }
  std::cout << "sum of price is: " << sum_p << std::endl;
  return 0;
}
