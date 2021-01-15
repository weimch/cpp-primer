#include <iostream>
#include <string>

class Sales_data {
 public:
  // 新增的构造函数
  Sales_data(std::string s, unsigned cnt, double price) :
    bookNo(s), units_sold(cnt), revenue(cnt*price) { }
  Sales_data() : Sales_data("", 0, 0) {}
  explicit Sales_data(std::string &s) : Sales_data(s, 0, 0) {}
  Sales_data(const std::string &s, unsigned n, double p) :
    bookNo(s), units_sold(n), revenue(p*n) {}
  explicit Sales_data(std::istream &) : Sales_data() {
    read(is, *this);
  }
  // 对象的操作
  std::string isbn() const { return bookNo; }
  Sales_data& combine(const Sales_data&);
 private:
  double avg_price() const;
  // 数据成员
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
// 非成员的接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
