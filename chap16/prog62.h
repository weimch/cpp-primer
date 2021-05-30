#pragma once

#include <iostream>
#include <string>

struct Sales_data;

std::istream &operator>>(std::istream &is, Sales_data &item);
std::ostream &operator<<(std::ostream &os, const Sales_data &item);
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);

struct Sales_data {
  friend std::istream &operator>>(std::istream &is, Sales_data &item);
  friend std::ostream &operator<<(std::ostream &os, const Sales_data &item);
  friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);
  friend bool operator==(const Sales_data &, const Sales_data &);
  friend class std::hash<Sales_data>;

 public:
  Sales_data(const std::string &s, unsigned n, double p) :
    bookNo(s), units_sold(n), revenue(p*n) {
    std::cout << "Sales_data(const std::string &s, unsigned n, double p)"
              << std::endl;
  }
  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "Sales_data() : Sales_data(\"\", 0, 0)" << std::endl;
  }
  explicit Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
    std::cout << "Sales_data(const std::string &s) : Sales_data" << std::endl;
  }
  explicit Sales_data(std::istream &is) : Sales_data() {
    is >> *this;
    std::cout << "Sales_data(std::istream &is) : Sales_data()" << std::endl;
  }
  std::string isbn() const {return bookNo;}
  Sales_data& operator=(const std::string&);
  Sales_data& operator+=(const Sales_data&);
  Sales_data& operator-=(const Sales_data&);

 private:
  inline double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
