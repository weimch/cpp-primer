#include "Sales_data.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

// namespace std {

// template <> struct hash<Sales_data> {
//   typedef size_t result_type;
//   typedef Sales_data argument_type;
//   size_t operator()(const Sales_data &) const;
// };

// size_t hash<Sales_data>::operator()(const Sales_data &s) const {
//   return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^
//          hash<double>()(s.revenue);
// }

// }  // namespace std

// bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
//   return lhs.isbn() < rhs.isbn();
// }

typedef std::tuple<std::vector<Sales_data>::size_type,
                   std::vector<Sales_data>::const_iterator,
                   std::vector<Sales_data>::const_iterator>
    matches;

std::vector<matches> findBook(const std::vector<std::vector<Sales_data>> &files,
                              const std::string &book) {
  std::vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it) {
    auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book),
                                  compareIsbn);
    if (found.first != found.second) {
      ret.push_back(
          std::make_tuple(it - files.cbegin(), found.first, found.second));
    }
  }
  return ret;
}

void reportResults(std::istream &in, std::ostream &os,
                   const std::vector<std::vector<Sales_data>> &files) {
  std::string s;
  while (in >> s) {
    auto trans = findBook(files, s);
    if (trans.empty()) {
      std::cout << s << " not found in any stores" << std::endl;
      continue;
    }
    for (const auto &store : trans) {
      os << "store " << std::get<0>(store) << " sales: "
         << std::accumulate(std::get<1>(store), std::get<2>(store),
                            Sales_data(s))
         << std::endl;
    }
  }
}

int main() {
  Sales_data sd1("001-01", 1, 100);
  Sales_data sd2("001-01", 2, 100);
  Sales_data sd3("001-02", 2, 80);

  std::vector<Sales_data> vs1 = {sd1, sd3};
  std::vector<Sales_data> vs2 = {sd2};
  std::vector<std::vector<Sales_data>> vvs = {vs1, vs2};
  reportResults(std::cin, std::cout, vvs);
  return 0;
}
