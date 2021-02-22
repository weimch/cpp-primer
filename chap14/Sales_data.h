#pragma once

#include <string>
#include <iostream>

class Sales_data {
  friend std::istream& operator>>(std::istream&, Sales_data&);
  friend std::ostream& operator<<(std::ostream&, const Sales_data&);
  friend Sales_data operator+(const Sales_data&, const Sales_data&);

 public:
  Sales_data(const std::string &s, unsigned n, double p)
    : bookNo(s), units_sold(n), revenue(n*p) {}
  Sales_data() : Sales_data("", 0, 0.0f) {}
  Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
  Sales_data(std::istream &is) : Sales_data() {
    is >> *this;
  }

  Sales_data& operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  std::string isbn() const { return bookNo; }

 private:
  double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  }

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::istream& operator>>(std::istream &is, Sales_data &item) {
  double price = 0.0;
  is >> item.bookNo >> item.units_sold >> price;
  if (is) {
    item.revenue = price * item.units_sold;
  } else {
    item = Sales_data();
  }
  return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " <<
    item.revenue << " " << item.avg_price();
  return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}
