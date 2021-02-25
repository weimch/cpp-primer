#pragma once

#include <iostream>
#include <string>
#include <utility>

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() { std::cout << "default construing Bulk_quote\n"; }
  Bulk_quote(const std::string &b, double p, std::size_t q, double disc) :
    Disc_quote(b, p, q, disc) {
    std::cout << "Bulk_quote : constructor taking 4 parameters\n";
  }
  Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
    std::cout << "Bulk_quote : copy constructor\n";
  }
  Bulk_quote(Bulk_quote &&bq) noexcept : Disc_quote(std::move(bq)) {
    std::cout << "Bulk_quote : move constructor\n";
  }
  Bulk_quote& operator=(const Bulk_quote& rhs) {
    Disc_quote::operator=(rhs);
    std::cout << "Bulk_quote : copy=()\n";
    return *this;
  }
  Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
    Disc_quote::operator=(std::move(rhs));
    std::cout << "Bulk_quote : move()\n";
    return *this;
  }
  double net_price(std::size_t n) const override;
  void debug() const override;
  ~Bulk_quote() override {
    std::cout << "destructing Bulk_quote\b";
  }
};
