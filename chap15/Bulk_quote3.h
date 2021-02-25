#pragma once

#include <string>
#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty,
    double disc) : Disc_quote(book, price, qty, disc) { }
  double net_price(std::size_t sz) const override {
    if (sz > quantity) {
      return sz * (1 - discount) * price;
    } else {
      return sz * price;
    }
  }
};
