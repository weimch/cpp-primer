#pragma once

#include <string>
#include <utility>
#include "Quote.h"

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double price) :
    Quote(book, p), min_qty(qty), discount(price) { }
  double net_price(std::size_t cnt) const override {
    if (cnt >= min_qty) {
      return cnt * (1 - discount) * price;
    } else {
      return cnt * price;
    }
  }
  void debug() const override {
    std::cout << "data members of this class:\n"
              << "min_qty=" << min_qty << " "
              << "discount=" << discount << "";
  }
  Bulk_quote* clone() const & { return new Bulk_quote(*this); }
  Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
 protected:
  std::size_t min_qty = 0;
  double discount = 0.0;
};
