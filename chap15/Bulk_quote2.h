#pragma once

#include <string>
#include "Bulk_quote.h"

class Bulk_quote2 : public Bulk_quote {
 public:
  Bulk_quote2(const std::string &book, double p, std::size_t qty,
    std::size_t uqty, double price) :
      Bulk_quote(book, p, qty, price), max_qty(uqty) { }
  double net_price(std::size_t cnt) const override {
    if (cnt >= min_qty && cnt < max_qty) {
      return cnt * (1 - discount) * price;
    } else {
      return cnt * price;
    }
  }
 private:
  std::size_t max_qty;
};
