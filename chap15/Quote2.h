#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <utility>

class Quote {
  friend bool operator !=(const Quote &lhs, const Quote &rhs);

 public:
  Quote() { std::cout << "default constructing Quote\n"; }
  Quote(const std::string &b, double p) : bookNo(b), price(p) {
    std::cout << "Quote : constructor taking 2 parameters\n";
  }
  Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
    std::cout << "Quote : copy constructing\n";
  }
  Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)),
    price(std::move(q.price)) {
    std::cout << "Quote : move construing\n";
  }
  Quote& operator=(const Quote& rhs) {
    if (*this != rhs) {
      bookNo = rhs.price;
      price = rhs.price;
    }
    std::cout << "Quote : copy=()\n";
    return *this;
  }
  Quote& operator=(Quote &&rhs) noexcept {
    if (*this != rhs) {
      bookNo = std::move(rhs.bookNo);
      price = std::move(rhs.price);
    }
    std::cout << "Quote : move=!!!!\n";
    return *this;
  }
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual void debug() const;
  virtual ~Quote() {
    std::cout << "destrucing Quote\n";
  }

 private:
  std::string bookNo;

 protected:
  double price;
};

bool inline operator!=(const Quote &lhs, const Quote &rhs) {
  return lhs.bookNo != rhs.bookNo
         &&
         lhs.price != rhs.price;
}
